#include "curves.h"
#include <math.h>
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
    float xPoint = xRad * static_cast<float>(cos(t));
    float yPoint = yRad * static_cast<float>(sin(t));
    std::vector<float> result = {xPoint, yPoint, 0};
    return result;
}

std::vector<float> Ellips::getFirstDerivative(float t) {
    float xPoint = -xRad * static_cast<float>(sin(t));
    float yPoint = yRad * static_cast<float>(cos(t));
    std::vector<float> result = {xPoint, yPoint, 0};
    return result;
}

std::string Ellips::getType() {
    return "Ellips";
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
    float xPoint = rad * static_cast<float>(cos(t));
    float yPoint = rad * static_cast<float>(sin(t));
    std::vector<float> result = {xPoint, yPoint, 0};
    return result;
}

std::vector<float> Circle::getFirstDerivative(float t) {
    float xPoint = -rad * static_cast<float>(sin(t));
    float yPoint = rad * static_cast<float>(cos(t));
    std::vector<float> result = {xPoint, yPoint, 0};
    return result;
}

float Circle::getRadius() {
    return rad;
}

std::string Circle::getType() {
    return "Circle";
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
    float xPoint = rad * static_cast<float>(cos(t));
    float yPoint = rad * static_cast<float>(sin(t));
    std::vector<float> result = {xPoint, yPoint, t * stepHelper};
    return result;
}

std::vector<float> Helix::getFirstDerivative(float t) {
    float xPoint = - rad * static_cast<float>(sin(t));
    float yPoint = rad * static_cast<float>(cos(t));
    std::vector<float> result = {xPoint, yPoint, stepHelper};
    return result;
}

std::string Helix::getType() {
    return "Helix";
}
// End helix realization
