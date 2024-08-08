#include <iostream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <vector>

#include "PoolAllocator.h"
#include "Scene.h"
#include "MenoBohaviour.h"
#include "PlayerController.h"
#include "BulletController.h"
#include "DblBuf.h"

#define FPS 30

/* この実習で学んだ様々なものを使って簡単なCUIのゲームを作ってみよう。
 * 作成するものは何でもよいが下記の要件を満たす事。
 * タイトル ゲームシーケンス 結果表示が存在しそれらがステートマシンによってコントロールされていること（任意)
 * クラスの多態性を用いたオブジェクト管理が入っていること(任意)
 * 自分が作成した Poolアロケータが使われていること(必須)
 * 何かしらの処理にスレッドを用いた並行処理が入っていること(任意)
 * ゲームエンジンの使用は不可
 * 使用する言語は C ++
 */

int main()
{
	/**const size_t MAXSIZE = 100;
	PoolAllocator<BulletController, MAXSIZE> alloc;

    DblBuf* buf = new DblBuf();

    std::vector<BulletController*> objs;*/

	Scene* s = new Scene();
	delete s;

    /*int phase = 0;
	bool quit = false;

	// エスケープシーケンスを有効に
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	while (!quit) {
        PlayerController* player = nullptr;
        BulletController* ptr = nullptr;
        switch (phase) {
        case 0:
            std::system("cls");
            std::cout << "Title" << std::endl;
            int i; //入力
            do
            {
                i = _getch(); // キー入力待ち
            } while ('q' != i && 's' != i);
            if ('s' == i) phase = 1;
            else quit = true;
            break;

        case 1:
            PlayerController * player = new PlayerController({ " | ", "###", "XXX" }, 10, 10, -1, -2, buf);
            BulletController* ptr = alloc.Alloc();
            ptr = new(ptr) BulletController({ "#" }, 12, 13, 0, 0, buf);
            objs.push_back(ptr);

            while (true) {
                auto start = std::chrono::high_resolution_clock::now();

                if (GetKeyState(81) & 0x8000) {
                    break;
                }

                for (auto obj : objs) {
                    obj->update();
                }
                player->update();

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
                alloc.Free(mb);
            }

            phase = 2;
            break;

        case 2:
            std::system("cls");
            std::cout << "Result" << std::endl;
            int j; //入力
            do
            {
                j = _getch(); // キー入力待ち
            } while ('c' != j);
            phase = 0;
            break;

        default:
            ptr = nullptr;
            player = nullptr;
        };
	}*/

	// カーソルを消す
	printf("\x1b[?25l");

	return EXIT_SUCCESS;
}
