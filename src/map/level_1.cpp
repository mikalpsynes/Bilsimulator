//
// Created by mikal on 07.10.2025.
//

#include "level_1.hpp"
#include "level.hpp"

#include "threepp/threepp.hpp"
using namespace threepp;

void Level1::init(std::shared_ptr<threepp::Scene> scene) {

    Level::init(scene);

    // Plane
    const auto plane = std::make_shared<Mesh>(
        BoxGeometry::create(20, 0.1, 20),
        MeshBasicMaterial::create()
    );

    root_->add(plane);

    // Door straight ahead
    auto doorMaterial = MeshBasicMaterial::create();
    doorMaterial->color = Color(0x0000ff);

    door_ = std::make_shared<Mesh>(BoxGeometry::create(1, 2, 0.2), doorMaterial);
    door_->position.set(0, 1, 20); // far away in +Z
    root_->add(door_);
}

Vector3 Level1::getDoorPosition() const {
    return door_->position;
}

Vector3 Level1::getStartPosition() const {
    return {0, 0.85f, -8};
}

