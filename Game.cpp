#include <chrono>
#include <thread>
#include <vector>
#include "DblBuf.h"
#include "MenoBohaviour.h"
#include "PlayerController.h"
#include "Scene.h"

#define FPS 2

void Scene::Game() {
    DblBuf buf;
    std::vector<MenoBohaviour*> objs = {
        new PlayerController("@", 10, 10, 0, 0),
        new PlayerController("#", 12, 13, 0, 0)
    };

    while (true) {
        buf.clear();
        auto start = std::chrono::high_resolution_clock::now();

        for (auto obj : objs) {
            obj->update();
        }

        for (auto obj : objs) {
            obj->render(buf);
        }

        //buf.swap();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS) - elapsed);
    }
}
