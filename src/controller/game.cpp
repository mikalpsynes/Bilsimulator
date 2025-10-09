#include <threepp/threepp.hpp>
#include "controller/game.hpp"

#include <iostream>

#include "KeyController.hpp"
#include "map/level.hpp"
#include "map/LevelManager.hpp"

using namespace threepp;

Game::Game() {
    canvas   = std::make_shared<Canvas>();
    renderer = std::make_shared<GLRenderer>(canvas->size());

    scene = Scene::create();
    scene->background = Color::aliceblue;

    camera = std::make_shared<PerspectiveCamera>(100.f, canvas->aspect(), 0.1f, 1000.f);
    camera->position.set(0, 10, 30);
    camera->lookAt(0, 0, 0);


    levelManager_ = std::make_unique<LevelManager>(scene);
    levelManager_->loadLevel(0); // start med level 1
    const auto startLevel = levelManager_->getCurrentLevel();
    scene->add(car.getGroup());
    car.getGroup()->position = startLevel->getStartPosition();


    controller = std::make_shared<KeyController>(car);
    canvas->addKeyListener(*controller);


    canvas->onWindowResize([&](const WindowSize& newSize){
        camera->aspect = newSize.aspect();
        camera->updateProjectionMatrix();
        renderer->setSize(newSize);
    });
}

void Game::run() {
    threepp::OrbitControls controls{ *camera, *canvas };
    controls.enableDamping = true;


    canvas->animate([&] {
    controls.update();
    car.update(0.016f);

    auto currentLevel = levelManager_->getCurrentLevel();
    if (!currentLevel) {
        return;
    };

    auto doorPos = currentLevel->getDoorPosition();
    auto carPos  = car.getGroup()->position;

    float dist = (doorPos - carPos).length();
    if (dist < 2.0f) {
        std::cout << "Reached door! Switching level..." << std::endl;
        levelManager_->nextLevel();
    }

    renderer->render(*scene, *camera);
});

}
