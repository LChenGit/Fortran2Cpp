#ifndef DIS_H
#define DIS_H

using wp = double; // Assuming wp corresponds to double precision

struct dis {
    wp x, y, z;
    wp mag, mag2;
    wp riy, rjy, yim;
    wp magim, mag2im;
    wp rjx, rjz;
    wp rix, riz;

    // Constructor to initialize members to zero
    dis() : x(0), y(0), z(0), mag(0), mag2(0), riy(0), rjy(0), yim(0),
            magim(0), mag2im(0), rjx(0), rjz(0), rix(0), riz(0) {}
};

#endif // DIS_H