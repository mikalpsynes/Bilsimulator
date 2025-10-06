//
// Created by mikal on 06.10.2025.
//

#include "controller/KeyController.hpp"

#include <iostream>
using namespace threepp;

KeyController::KeyController(Car &car) : car_(car) {}

void KeyController::onKeyPressed(threepp::KeyEvent evt) {
    switch (evt.key) {
        case threepp::Key::W: car_.setSpeed(8.f); break;
        case threepp::Key::S: car_.setSpeed(-4.f); break;
        case threepp::Key::A: car_.setRotationSpeed(2.f); break;
        case threepp::Key::D: car_.setRotationSpeed(-2.f); break;
        default: break;
    }
}

void KeyController::onKeyReleased(threepp::KeyEvent evt) {
    switch (evt.key) {
        case threepp::Key::W:
        case threepp::Key::S:
            car_.setSpeed(0.f);
            break;
        case threepp::Key::A:
        case threepp::Key::D:
            car_.setRotationSpeed(0.f);
            break;
        default: break;
    }
}
