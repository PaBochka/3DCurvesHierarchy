#pragma once
#include <vector>
#include <string>
#include <map>
#define M_PI 3.14159265358979323846

class ICurve
{
public:
    virtual ~ICurve() = default;
    virtual std::vector<float> getPoint(float t) = 0;
    virtual std::vector<float> getFirstDerivative(float t) = 0;
    virtual std::string getType() = 0;
};

class Ellips : public ICurve {
private:
    float xRad;
    float yRad;
public:
    Ellips(float _xRad, float _yRad);
    virtual ~Ellips() = default;
    virtual std::vector<float> getPoint(float t) override;
    virtual std::vector<float> getFirstDerivative(float t) override;
    virtual std::string getType() override;
};

class Circle : public Ellips {
private:
    float rad;
public:
    Circle(float _rad);
    ~Circle() = default;
    float getRadius();
    std::string getType() override;
};

class Helix : public ICurve {
private:
    float rad;
    float stepHelper;
public:
    Helix(float _rad, float _stepHelper = 1);
    ~Helix() = default;
    std::vector<float> getPoint(float t) override;
    std::vector<float> getFirstDerivative(float t) override;
    std::string getType() override;
};
