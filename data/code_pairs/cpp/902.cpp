#include <iostream>
#include <cassert>

class UpdateVelocElasticNewmark {
public:
    static float updateVelocElasticNewmark(float old_velocity, float acceleration, float time) {
        return old_velocity + acceleration * time;
    }
};