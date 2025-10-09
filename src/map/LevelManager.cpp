//
// Created by mikal on 07.10.2025.
//

#include "LevelManager.hpp"

#include <iostream>

#include "level_1.hpp"
#include "level_2.hpp"

LevelManager::LevelManager(const std::shared_ptr<threepp::Scene> &scene) : scene_(scene) {

    addLevel(std::make_unique<Level1>());
    addLevel(std::make_unique<Level2>());

}

void LevelManager::addLevel(std::unique_ptr<Level> level) {
    levels_.push_back(std::move(level));
}

// chat gpt
void LevelManager::loadLevel(const int index) {
    if (index >= 0 && index < levels_.size()) {
        // bare fjern forrige hvis det faktisk er forskjellig fra første load
        if (currentLevelIndex_ >= 0 &&
            currentLevelIndex_ < levels_.size() &&
            levels_[currentLevelIndex_] &&
            levels_[currentLevelIndex_]->getRoot()) {
            scene_->remove(*levels_[currentLevelIndex_]->getRoot());
            }

        std::cout << "Loading level " << index+1 << std::endl;
        currentLevelIndex_ = index;
        levels_[index]->init(scene_);
    }
}


int LevelManager::getCurrentLevelIndex() const {
    return currentLevelIndex_;
}

void LevelManager::nextLevel() {
    if (currentLevelIndex_ + 1 < levels_.size()) {
        loadLevel(currentLevelIndex_+1);
    }
    else {
        loadLevel(0);
    }
}

Level* LevelManager::getCurrentLevel() {
    return levels_[currentLevelIndex_].get();
}





