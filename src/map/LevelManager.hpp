//
// Created by mikal on 07.10.2025.
//

#ifndef BILSIMULATOR_LEVELMANAGER_HPP
#define BILSIMULATOR_LEVELMANAGER_HPP
#include "threepp/threepp.hpp"
#include "map/level.hpp"


class LevelManager {
public:
    explicit LevelManager(const std::shared_ptr<threepp::Scene> &scene);

    void addLevel(std::unique_ptr<Level> level);
    void loadLevel(int index);
    void nextLevel();

    int getCurrentLevelIndex() const;
    Level* getCurrentLevel();


private:
    std::shared_ptr<threepp::Scene> scene_;
    std::vector<std::unique_ptr<Level>> levels_;
    int currentLevelIndex_ = 0;
    std::unique_ptr<Level> activeLevel_;
};

#endif //BILSIMULATOR_LEVELMANAGER_HPP