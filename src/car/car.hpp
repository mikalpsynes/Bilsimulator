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
    void rotateWheels(float degrees) const;
    void drive(float speed);

private:
    std::shared_ptr<threepp::Group> carGroup;
    std::shared_ptr<threepp::Mesh> carBody;
    std::vector<std::shared_ptr<threepp::Mesh>> carWheels;
};

#endif //BILSIMULATOR_CAR_HPP