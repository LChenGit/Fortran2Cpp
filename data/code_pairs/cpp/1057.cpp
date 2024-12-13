#ifndef UPDATE_VELOC_ACOUSTIC_H
#define UPDATE_VELOC_ACOUSTIC_H

class UpdateVelocAcoustic {
public:
    static void updateVelocAcoustic(int nglob, float* velocOuterCore, float* accelOuterCore, float deltaTover2);
};

#endif // UPDATE_VELOC_ACOUSTIC_H