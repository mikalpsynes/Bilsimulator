//
// Created by mikal on 07.10.2025.
//

#ifndef BILSIMULATOR_LEVEL_2_HPP
#define BILSIMULATOR_LEVEL_2_HPP

#include "level.hpp"

class Level2 : public Level {
public:
    void init(std::shared_ptr<threepp::Scene> scene) override;
    [[nodiscard]] threepp::Vector3 getDoorPosition() const override;
    [[nodiscard]] threepp::Vector3 getStartPosition() const override;


private:
    std::shared_ptr<threepp::Mesh> door_;
};

#endif //BILSIMULATOR_LEVEL_2_HPP