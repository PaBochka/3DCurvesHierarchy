#include "curves.h"
#include <cmath>
#include <stdexcept>

// Ellips realization
Ellips::Ellips(float _xRad, float _yRad) {
    if(_xRad <= 0 || _yRad <= 0) {
        throw std::runtime_error("radii is lower or equal then 0");
    }
    else {
        xRad = _xRad;
        yRad = _yRad;
    }
}

std::vector<float> Ellips::getPoint(float t) {
    float xPoint = xRad * static_cast<float>(std::cos(t));
    float yPoint = yRad * static_cast<float>(std::sin(t));
    return {xPoint, yPoint, 0};
}

std::vector<float> Ellips::getFirstDerivative(float t) {
    float xPoint = -xRad * static_cast<float>(std::sin(t));
    float yPoint = yRad * static_cast<float>(std::cos(t));
    return {xPoint, yPoint, 0};
}
// End ellips realization

// Circle realization
Circle::Circle(float _rad) : rad(_rad) {
    if(_rad <= 0) {
        throw std::runtime_error("radius is lower or equal then 0");
    }
    else {
        rad = _rad;
    }
}

std::vector<float> Circle::getPoint(float t) {
    float xPoint = rad * static_cast<float>(std::cos(t));
    float yPoint = rad * static_cast<float>(std::sin(t));
    return {xPoint, yPoint, 0};
}

std::vector<float> Circle::getFirstDerivative(float t) {
    float xPoint = -rad * static_cast<float>(std::sin(t));
    float yPoint = rad * static_cast<float>(std::cos(t));
    return {xPoint, yPoint, 0};
}

float Circle::getRadius() {
    return rad;
}
// End cirlce realization

// Helix realization
Helix::Helix(float _rad, float _stepHelper) : rad(_rad), stepHelper(_stepHelper){
    if(_rad <= 0) {
        throw std::runtime_error("radius is lower or equal then 0");
    }
    else {
        rad = _rad;
        stepHelper = _stepHelper;
    }
}

std::vector<float> Helix::getPoint(float t) {
    float xPoint = rad * static_cast<float>(std::cos(t));
    float yPoint = rad * static_cast<float>(std::sin(t));
    return {xPoint, yPoint, static_cast<float>(t * stepHelper / (2 * std::numbers::pi))};
}

std::vector<float> Helix::getFirstDerivative(float t) {
    float xPoint = - rad * static_cast<float>(std::sin(t));
    float yPoint = rad * static_cast<float>(std::cos(t));
    return {xPoint, yPoint, static_cast<float>(stepHelper / (2 * std::numbers::pi))};
}
// End helix realization
