#include <chrono>
#include <thread>
#include <vector>
#include "DblBuf.h"
#include "MenoBohaviour.h"
#include "BulletController.h"
#include "PlayerController.h"
#include "Scene.h"
#include "PoolAllocator.h"
#include <iostream>

#define FPS 30

void Scene::Game() {
    DblBuf* buf = new DblBuf();

    const int MB_SIZE = 100;
    PoolAllocator<BulletController, MB_SIZE> a;
    std::vector<BulletController*> objs;

    /*for (int i = 0; i < MB_SIZE; ++i) {
        objs[i] = a.Alloc();
        if (nullptr == objs[i]) {
            std::cout << i << "ŒÂ–Ú‚Ìƒƒ‚ƒŠŠm•Û‚ÉŽ¸”s" << std::endl;
            return;
        }
        MenoBohaviour* mb = new(objs[i]) MenoBohaviour({"#"}, 12 + i, 13, 0, 0, buf, &objs);
    }*/

    PlayerController* player = new PlayerController({" | ", "###", "XXX"}, 10, 10, -1, -2, buf);

    while (true) {
        auto start = std::chrono::high_resolution_clock::now();

        if (GetKeyState(81) & 0x8000) {
            break;
        }

        for (size_t i = 0; i < objs.size(); i++) {
            objs[i]->update();
            if (objs[i]->dead) {
                a.Free(objs[i]);  // ƒƒ‚ƒŠ‰ð•úˆ—
                objs.erase(objs.begin() + i);  // Œ»Ý‚Ì—v‘f‚ðíœ
            }
        }
        player->update();
        if (player->shoot) {
            player->shoot = false;
            BulletController* ptr = a.Alloc();
            ptr = new(ptr) BulletController({ "o" }, player->transform.X, player->transform.Y, 0, 0, buf);
            objs.push_back(ptr);
        }

        for (auto obj : objs) {
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
    /*for (int i = 0; i < MB_SIZE; i++) {
        a.Free(objs[i]);
        objs[i] = nullptr;
    }*/

    Result();
}
