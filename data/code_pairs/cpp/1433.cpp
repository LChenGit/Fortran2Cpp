// FluidModelToy.h
#ifndef FLUID_MODEL_TOY_H
#define FLUID_MODEL_TOY_H

class FluidModelToy {
public:
    double density;
    double velocity;
    double pressure;

    FluidModelToy() : density(0.0), velocity(0.0), pressure(0.0) {}

    void initialize() {
        density = 1.0;
        velocity = 2.0;
        pressure = 101.3;
    }

    void calculate() {
        pressure = density * velocity * 2.0;
    }

    void deleteModel() {
        density = 0.0;
        velocity = 0.0;
        pressure = 0.0;
    }
};

#endif // FLUID_MODEL_TOY_H