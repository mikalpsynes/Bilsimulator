//
// Created by mikal on 02.10.2025.
//

#include "level.hpp"
#include <threepp/threepp.hpp>
using namespace threepp;

void Level::init(std::shared_ptr<threepp::Scene> scene) {
    auto planeGeometry = BoxGeometry::create(20, 0.1, 20);
    auto planeMaterial = MeshBasicMaterial::create();
    planeMaterial->color = Color(0x228833); // grønn farge

    const auto plane = std::make_shared<Mesh>(planeGeometry, planeMaterial);
    scene->add(plane);

    auto doorGeometry = BoxGeometry::create(1, 2, 0.2);
    auto doorMaterial = MeshBasicMaterial::create();
    doorMaterial->color = Color(0x0000ff);

    const auto door = std::make_shared<Mesh>(doorGeometry, doorMaterial);
    door->position = Vector3(0, 1, 5);
    scene->add(door);
}


