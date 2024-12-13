#ifndef MYGA_PARAMS_H
#define MYGA_PARAMS_H

struct MYGA_PARAMS {
    static int MYGA_NSTRUC, MYGA_NOFF;
    static int MYGA_NMUT;
    static int MYGA_GENS;
    static int MYGA_TOURN_SIZE;
    static bool MYGA_L_EPOCH;
    static int MYGA_EPOCH_SAVE;
    static bool MYGA_EPOCH_DUMP;
    static int MYGA_COUNT_EPOCH;
    static double MYGA_MUT_RATE;
    static int MYGA_CROSS;
    static double MYGA_BQMAX, MYGA_CQMAX;
    static double MYGA_DUPLICATE_ETHRESH;
    static double MYGA_DUPLICATE_GTHRESH;
    static double MYGA_EPOCH_THRESH;
    static double MYGA_LAST_ENERGY;
    static bool MYGA_L_ROUL;
    static bool MYGA_L_CHAIN;
    static bool MYGA_L_SPHERE;
    static double MYGA_SPHERE_RADIUS;
    static int MYGA_COUNT_MIN;
    static int CURR_GEN;
    static double MYGA_BH_INIT;
    static double MYGA_BH_INCR;
    static double MYGA_BH_STEPS;
    static bool MYGA_DUMP_POP;
    static bool MYGA_TWIN;
};

#endif // MYGA_PARAMS_H