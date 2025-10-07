//
// Created by mikal on 02.10.2025.
//

#ifndef BILSIMULATOR_CAR_HPP
#define BILSIMULATOR_CAR_HPP
#include <memory>
#include <vector>

namespace threepp {
    class Mesh;
    class Group;
}

class Car {
public:
    Car();
    std::shared_ptr<threepp::Group> getGroup();
    void update(float dt);

    void setSpeed(float speed);
    float getSpeed() const;

    void setRotationSpeed(float speed);
    float getRotationSpeed() const;

private:
    std::shared_ptr<threepp::Group> carGroup;
    std::shared_ptr<threepp::Mesh> carBody;
    std::shared_ptr<threepp::Mesh> carBubble;
    std::vector<std::shared_ptr<threepp::Mesh>> carWheels;
    float speed_ = 0;
    float rotationSpeed_ = 0;
};

#endif //BILSIMULATOR_CAR_HPP