#include "Curves/curves.h"
#include <memory>
#include <random>
#include <iostream>
#include <algorithm>
#include <numeric>

// Function for generate randon uint value
uint32_t generateRandValue(uint32_t val) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, val);
    return distrib(gen);
}

// Function for auto initializing the vector of curves.
// This function is optional, and you can create the curve or pointer on curve
// and push in vector or just use.
std::vector<std::shared_ptr<ICurve>> createCurves(size_t count) {
    std::vector<std::shared_ptr<ICurve>> result;
    for(size_t i = 0; i < count; ++i) {
        auto randomValue = generateRandValue(2);
        switch(randomValue) {
        case 0: {
            result.emplace_back(std::make_shared<Ellips>(static_cast<float>(generateRandValue(9) + 1),
                                                         static_cast<float>(generateRandValue(9) + 1)));
            break;
        }
        case 1: {
            result.emplace_back(std::make_shared<Circle>(static_cast<float>(generateRandValue(9) + 1)));
            break;
        }
        case 2: {
            result.emplace_back(std::make_shared<Helix>(static_cast<float>(generateRandValue(9) + 1)));
            break;
        }
    }
    }
    return result;
}

int main(int argc, char *argv[]) {
    // Initing vector of curves with random curve with random parametres
    std::vector<std::shared_ptr<ICurve>> curves = createCurves(10);

    // Print point and derivative for all curves
    for(const auto &curve : curves) {
        std::vector<float> point = curve->getPoint(static_cast<float>(M_PI / 4));
        std::vector<float> firstDer = curve->getFirstDerivative(static_cast<float>(M_PI / 4));
        std::cout << "point\n";
        std::cout << "{ x: " << point[0] << ", y: " << point[1] << ", z: " << point[2] << " }\n";
        std::cout << "derivative\n";
        std::cout << "{ x: " << firstDer[0] << ", y: " << firstDer[1] << ", z: " << firstDer[2] << " }\n";
    }

    // Populating a second container that would contain only circles from the first container.
    std::vector<std::shared_ptr<ICurve>> circles;
    for(const auto &curve : curves) {
        if(curve->getType() == "Circle") {
            circles.push_back(curve);
        }
    }

    // Sorting circles's container
    std::sort(circles.begin(), circles.end(), [](const auto &left, const auto &right) -> bool {return left->getRadius().first < right->getRadius().first;});
    for (const auto &circle : circles) {
        std::cout << circle->getRadius().first << " ";
    }
    std::cout << std::endl;

    //Computing total sum of radii
    auto sum = std::accumulate(circles.begin(), circles.end(), 0.0f,
            [](auto start_val, const auto &circle) -> float {return start_val + circle->getRadius().first;});
    std::cout << "Total sum: " << sum << std::endl;

    return 0;
}
