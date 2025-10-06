#include <threepp/threepp.hpp>
#include "controller/game.hpp"

#include "KeyController.hpp"
#include "map/level.hpp"

using namespace threepp;

Game::Game() {
    canvas   = std::make_shared<Canvas>();
    renderer = std::make_shared<GLRenderer>(canvas->size());

    scene = Scene::create();
    scene->background = Color::aliceblue;

    camera = std::make_shared<PerspectiveCamera>(100.f, canvas->aspect(), 0.1f, 1000.f);
    camera->position.z = 30;

    level.init(scene);
    scene->add(car.getGroup());

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
        renderer->render(*scene, *camera);
    });
}
