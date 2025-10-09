//
// Created by mikal on 07.10.2025.
//

#include "level_2.hpp"
#include "threepp/threepp.hpp"
using namespace threepp;

void Level2::init(std::shared_ptr<threepp::Scene> scene) {
    Level::init(scene);

    // Bigger plane
    const auto plane = std::make_shared<Mesh>(
        BoxGeometry::create(30, 0.1, 30),
        MeshBasicMaterial::create()
    );
    root_->add(plane);

    // Door to the right side
    auto doorMaterial = MeshBasicMaterial::create();
    doorMaterial->color = Color(0x00ff00);

    door_ = std::make_shared<Mesh>(BoxGeometry::create(1, 2, 0.2), doorMaterial);
    door_->position.set(10, 1, 8); // offset on X
    root_->add(door_);
}

Vector3 Level2::getDoorPosition() const {
    return door_->position;
}

Vector3 Level2::getStartPosition() const {
    return {0, 0.85f, -8};
}
