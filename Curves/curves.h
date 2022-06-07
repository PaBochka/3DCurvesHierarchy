#pragma once
#include <vector>
#include <string>
#include <map>
#define M_PI 3.14159265358979323846

class ICurve
{
public:
    virtual ~ICurve() {}
    virtual std::vector<float> getPoint(float t) = 0;
    virtual std::vector<float> getFirstDerivative(float t) = 0;
    virtual std::string getType() = 0;
    virtual std::pair<float, float> getRadius() = 0;
};

class Ellips : public ICurve {
public:
    float xRad;
    float yRad;
    Ellips(float _xRad, float _yRad);
    ~Ellips();
    virtual std::vector<float> getPoint(float t) override;
    virtual std::vector<float> getFirstDerivative(float t) override;
    virtual std::string getType() override;
    virtual std::pair<float, float> getRadius() override;
};

class Circle : public Ellips {
public:
    float rad;
    Circle(float _rad);
    ~Circle();
    std::string getType() override;
};

class Helix : public ICurve {
public:
    float rad;
    float stepHelper;
    Helix(float _rad, float _stepHelper = 1);
    ~Helix();
    std::vector<float> getPoint(float t) override;
    std::vector<float> getFirstDerivative(float t) override;
    std::string getType() override;
    std::pair<float, float> getRadius() override;
};
