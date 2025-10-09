//
// Created by mikal on 08.10.2025.
//

#include <cassert>
#include <iostream>
#include "car/car.hpp"
#include "map/LevelManager.hpp"
#include "map/level_1.hpp"
#include "map/level_2.hpp"
#include "threepp/threepp.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace threepp;


TEST_CASE("Car speed can be set and retrieved") {
    Car car;
    car.setSpeed(5.f);
    REQUIRE(car.getSpeed() == 5.f);
}

TEST_CASE("Car starts with zero speed") {
    Car car;
    REQUIRE(car.getSpeed() == 0.f);
}

TEST_CASE("LevelManager can add and load levels") {
    auto scene = threepp::Scene::create();
    LevelManager manager(scene);

    manager.addLevel(std::make_unique<Level1>());
    manager.addLevel(std::make_unique<Level2>());

    REQUIRE(manager.getCurrentLevelIndex() == 0);

    manager.loadLevel(0);
    REQUIRE(manager.getCurrentLevelIndex() == 0);

    manager.nextLevel();
    REQUIRE(manager.getCurrentLevelIndex() == 1);
}


TEST_CASE("Door position is set in Level1") {
    auto scene = threepp::Scene::create();
    Level1 level;
    level.init(scene);

    auto doorPos = level.getDoorPosition();
    REQUIRE(doorPos.z != 0); // døra skal ikke være i (0,0,0)
}

TEST_CASE("Car detects door proximity") {
    using namespace threepp;

    auto scene = Scene::create();
    Level1 level;
    level.init(scene);

    Car car;
    car.getGroup()->position.set(0, 0.85f, 0); // Startposisjon

    auto doorPos = level.getDoorPosition();
    auto carPos  = car.getGroup()->position;

    float dist = (doorPos - carPos).length();

    SECTION("Car is far from door initially") {
        REQUIRE(dist > 2.0f);
    }

    SECTION("Car near door triggers proximity") {
        car.getGroup()->position = level.getDoorPosition(); // plasser bilen rett på døra
        auto dist = (car.getGroup()->position - level.getDoorPosition()).length();
        REQUIRE(dist < 2.0f);
    }

}