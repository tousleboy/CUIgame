#include <chrono>
#include <thread>
#include <vector>
#include "DblBuf.h"
#include "MenoBohaviour.h"
#include "BulletController.h"
#include "PlayerController.h"
#include "EnemyController.h"
#include "Scene.h"
#include "PoolAllocator.h"
#include <iostream>
#include <random>

#define FPS 30

void Scene::Game() {
    score = 0;

    std::random_device rd; // ハードウェア乱数生成器を使ってシードを取得
    std::mt19937 gen(rd()); // メルセンヌ・ツイスタエンジンのインスタンス
    std::uniform_int_distribution<> dis(0, 80); // -1から1までの整数の一様分布

    DblBuf* buf = new DblBuf();

    const int MB_SIZE = 100;
    PoolAllocator<BulletController, MB_SIZE> a;
    std::vector<BulletController*> objs;

    const int EC_SIZE = 20;
    PoolAllocator<EnemyController, EC_SIZE> ea;
    std::vector<EnemyController*> enms;

    PlayerController* player = new PlayerController({" | ", "###", "XXX"}, 10, 10, -1, -2, buf);

    int time = 0;
    int enemy_spawn = 5;
    while (!(player->dead || score >= 50)) {
        auto start = std::chrono::high_resolution_clock::now();

        time = (time + 1) % (enemy_spawn + 1);

        if (time >= enemy_spawn && enms.size() < EC_SIZE) {
            EnemyController* eptr = ea.Alloc();
            eptr = new(eptr) EnemyController({ "EEE", "EEE", "E E"}, dis(gen), player->transform.Y - 10, -1, -2, buf);
            enms.push_back(eptr);
        }

        if (GetKeyState(81) & 0x8000) {
            break;
        }

        for (size_t i = 0; i < objs.size(); i++) {
            objs[i]->update();
            if (objs[i]->dead) {
                a.Free(objs[i]);  // メモリ解放処理
                objs.erase(objs.begin() + i);  // 現在の要素を削除
            }
        }
        for (size_t i = 0; i < enms.size(); i++) {
            enms[i]->update();
            if (enms[i]->dead) {
                ea.Free(enms[i]);  // メモリ解放処理
                enms.erase(enms.begin() + i);  // 現在の要素を削除
                score++;
            }
        }
        player->update();

        if (player->shoot) {
            player->shoot = false;
            BulletController* ptr = a.Alloc();
            ptr = new(ptr) BulletController({ "o" }, player->transform.X, player->transform.Y - 2, 0, 0, buf);
            objs.push_back(ptr);
        }

        for (auto obj : objs) {
            obj->render();
        }
        for (auto obj : enms) {
            obj->render();
        }

        player->render();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS) - elapsed);
        buf->swap();
    }
    delete buf;
    delete player;
    for (auto mb : objs) {
        a.Free(mb);
    }
    for (auto ec : enms) {
        ea.Free(ec);
    }
    /*for (int i = 0; i < MB_SIZE; i++) {
        a.Free(objs[i]);
        objs[i] = nullptr;
    }*/

    Result();
}
