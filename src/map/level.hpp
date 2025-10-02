//
// Created by mikal on 02.10.2025.
//

#ifndef BILSIMULATOR_MAP_HPP
#define BILSIMULATOR_MAP_HPP
#pragma once
#include <memory>

namespace threepp { class Scene; }

class Level {
public:
    void init(std::shared_ptr<threepp::Scene> scene);
};

#endif //BILSIMULATOR_MAP_HPP