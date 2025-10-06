//
// Created by mikal on 02.10.2025.
//

#include "car.hpp"

#include <threepp/threepp.hpp>
using namespace threepp;

Car::Car() {
    // Car Body
    auto carBodyGeometry = BoxGeometry::create(2, 0.5, 4);
    auto carBodyMaterial = MeshBasicMaterial::create();
    carBodyMaterial->color = Color::red;
    carBody = std::make_shared<Mesh>(carBodyGeometry, carBodyMaterial);

    // Car Wheels
    auto carWheelsGeometry = CylinderGeometry::create(0.5, 0.5, 0.3, 32);
    auto carWheelsMaterial = MeshBasicMaterial::create();
    carWheelsMaterial->color = Color(0x000000);

    auto carWheelLF = std::make_shared<Mesh>(carWheelsGeometry, carWheelsMaterial);
    carWheelLF->position.set(-1.2f, -0.3f,  2.f);
    auto carWheelRF = std::make_shared<Mesh>(carWheelsGeometry, carWheelsMaterial);
    carWheelRF->position.set( 1.2f, -0.3f,  2.f);
    auto carWheelLB = std::make_shared<Mesh>(carWheelsGeometry, carWheelsMaterial);
    carWheelLB->position.set(-1.2f, -0.3f, -2.f);
    auto carWheelRB = std::make_shared<Mesh>(carWheelsGeometry, carWheelsMaterial);
    carWheelRB->position.set( 1.2f, -0.3f, -2.f);
    carWheels = {carWheelLF, carWheelRF, carWheelLB, carWheelRB};

    // Car Group
    carGroup = std::make_shared<Group>();
    carGroup->add(carBody);
    for (const auto & carWheel : carWheels) {
        carWheel->rotation.z = math::PI / 2;
        carGroup->add(carWheel);
    }
    carGroup->position.y = 0.85f;   // wheel radius (0.5) - wheel y (-0.3) + plane height (0.1) / 2
}


std::shared_ptr<threepp::Group> Car::getGroup() {
    return carGroup;
}


// chat gpt
void Car::update(const float dt) {

    carGroup->rotation.y += rotationSpeed_ * dt;

    // Move car
    const float distance = speed_ * dt;
    const float carAngle = carGroup->rotation.y;

    carGroup->position.x += std::sin(carAngle) * distance;
    carGroup->position.z += std::cos(carAngle) * distance;

    // Rotate wheels
    if (speed_ != 0) {
        for (auto& carWheel : carWheels) {
            carWheel->rotation.x += distance;
        }
    }
}

void Car::setSpeed(const float speed) {
    speed_ = speed;
}

float Car::getSpeed() const {
    return speed_;
}

void Car::setRotationSpeed(const float speed) {
    rotationSpeed_ = speed;
}

float Car::getRotationSpeed() const {
    return rotationSpeed_;
}