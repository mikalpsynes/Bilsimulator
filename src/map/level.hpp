//
// Created by mikal on 02.10.2025.
//

#ifndef BILSIMULATOR_MAP_HPP
#define BILSIMULATOR_MAP_HPP
#pragma once
#include <memory>

#include "threepp/threepp.hpp"


namespace threepp {
    class Vector3;
    class Mesh;
    class Scene; }

class Level {
public:
    virtual ~Level() = default;

    virtual void init(std::shared_ptr<threepp::Scene> scene) {
        if (!root_) {
            root_ = std::make_shared<threepp::Group>();
            scene->add(root_);
        } else {
            root_->clear(); // fjerner alt inni root før vi legger til på nytt
        }
        scene->add(root_);
    };

    virtual threepp::Vector3 getDoorPosition() const = 0;
    virtual threepp::Vector3 getStartPosition() const = 0;

    std::shared_ptr<threepp::Group> getRoot() { return root_; }


protected:
    std::shared_ptr<threepp::Group> root_;
    std::shared_ptr<threepp::Mesh> door_;
};

#endif //BILSIMULATOR_MAP_HPP