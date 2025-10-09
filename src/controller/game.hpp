#ifndef BILSIMULATOR_GAME_HPP
#define BILSIMULATOR_GAME_HPP

#include <memory>

#include "KeyController.hpp"
#include "car/car.hpp"
#include "map/level.hpp"
#include "map/LevelManager.hpp"

// Forward declarations (slipper å inkludere tunge headers her)
namespace threepp { 
    class Scene; 
    class PerspectiveCamera; 
    class Canvas; 
    class GLRenderer; 
}

class Game {
public:
    Game();
    void run();

private:
    std::shared_ptr<threepp::Canvas> canvas;
    std::shared_ptr<threepp::GLRenderer> renderer;
    std::shared_ptr<threepp::Scene> scene;
    std::shared_ptr<threepp::PerspectiveCamera> camera;

    std::unique_ptr<LevelManager> levelManager_;
    Car car;
    std::shared_ptr<KeyController> controller;

    bool transitioning_ = false;
};

#endif // BILSIMULATOR_GAME_HPP
