//
// Created by mikal on 02.10.2025.
//

#ifndef BILSIMULATOR_INPUT_HPP
#define BILSIMULATOR_INPUT_HPP

#include "car/car.hpp"
#include "threepp/input/KeyListener.hpp"

class KeyController : public threepp::KeyListener {

public:
    explicit KeyController(Car& car);

    void onKeyPressed(threepp::KeyEvent evt) override;
    void onKeyReleased(threepp::KeyEvent evt) override;

private:
    Car& car_;
};

#endif //BILSIMULATOR_INPUT_HPP