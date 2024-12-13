// misc_values.h
#ifndef MISC_VALUES_H
#define MISC_VALUES_H

typedef double dp; // Assuming double precision is desired

struct MiscValues {
    dp mv_leafmol;
    dp mv_soilw;
    dp mv_soil2g;
    dp mv_respref;
};

extern MiscValues msv;

#endif // MISC_VALUES_H