//
// Created by mikal on 02.10.2025.
//

#include "car.hpp"

#include <threepp/threepp.hpp>
using namespace threepp;

Car::Car() {
    // Variables
    constexpr float carBodyWidth = 2;
    constexpr float carBodyHeight = 1;
    constexpr float carBodyDepth = 4;

    constexpr float carBubbleRadius = 1;
    constexpr float carBubbleHeight = carBodyWidth;

    constexpr float wheelRadius = 0.5f;
    constexpr float wheelWidth  = 0.3f;
    constexpr float rimRadius   = wheelRadius * 0.6f;
    constexpr float rimWidth   = wheelWidth *1.01f;

    // Car Base
    auto carBodyGeometry = BoxGeometry::create(carBodyWidth, carBodyHeight, carBodyDepth);
    auto carBodyMaterial = MeshBasicMaterial::create();
    carBodyMaterial->color = Color::red;

    carBody = std::make_shared<Mesh>(carBodyGeometry, carBodyMaterial);

    // Car Bubble
    auto carBubbleGeometry = CylinderGeometry::create(carBubbleRadius, carBubbleRadius, carBubbleHeight, 32, 1);

    carBubble = std::make_shared<Mesh>(carBubbleGeometry, carBodyMaterial);
    carBubble->rotation.z = math::PI / 2;
    carBubble->position.y = 0.6f;
    carBubble->position.z = -carBodyDepth/2 + carBubbleRadius;

    // Car Wheels & Rims
    auto carWheelsGeometry = CylinderGeometry::create(wheelRadius, wheelRadius, wheelWidth, 32);
    const auto carWheelsMaterial = MeshBasicMaterial::create();
    carWheelsMaterial->color = Color(0x000000);

    auto rimGeometry = CylinderGeometry::create(rimRadius, rimRadius, rimWidth);
    const auto rimMaterial = MeshBasicMaterial::create();
    rimMaterial->color = Color(0xffffff);


    auto makeWheel = [&](const float x, const float z, const bool leftSide) {
        auto wheel = std::make_shared<Mesh>(carWheelsGeometry, carWheelsMaterial);

        // Rim
        const auto rim = std::make_shared<Mesh>(rimGeometry, rimMaterial);
        wheel->add(rim);

        wheel->position.set(x, -0.3f, z);
        wheel->rotation.z = math::PI / 2;
        return wheel;
    };

    auto carWheelLF = makeWheel(-1.2f,  2.f, true);
    auto carWheelRF = makeWheel( 1.2f,  2.f, false);
    auto carWheelLB = makeWheel(-1.2f, -2.f, true);
    auto carWheelRB = makeWheel( 1.2f, -2.f, false);

    carWheels = {carWheelLF, carWheelRF, carWheelLB, carWheelRB};

    // Front Lights
    auto lightGeometry = SphereGeometry::create(0.2f, 8, 8);
    const auto lightMaterial = MeshBasicMaterial::create();
    lightMaterial->color = Color(0xffff00);

    const auto leftLight = std::make_shared<Mesh>(lightGeometry, lightMaterial);
    leftLight->position.set(-0.6f, 0.2f, 2.1f);

    const auto rightLight = std::make_shared<Mesh>(lightGeometry, lightMaterial);
    rightLight->position.set(0.6f, 0.2f, 2.1f);


    // Spoiler
    auto spoilerGeometry = BoxGeometry::create(1.5f, 0.1f, 0.4f);
    auto spoilerMaterial = MeshBasicMaterial::create();
    spoilerMaterial->color = Color(0x333333);
    const auto spoiler = std::make_shared<Mesh>(spoilerGeometry, spoilerMaterial);
    spoiler->position.set(0, 0.6f, -2.1f);


    // Car Group
    carGroup = std::make_shared<Group>();
    carGroup->add(carBody);
    carGroup->add(carBubble);
    for (const auto & carWheel : carWheels) {
        carGroup->add(carWheel);
    }
    carGroup->add(leftLight);
    carGroup->add(rightLight);
    carGroup->add(spoiler);

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