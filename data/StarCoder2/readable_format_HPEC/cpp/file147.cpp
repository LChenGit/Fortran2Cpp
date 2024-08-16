#include <algorithm> // For std::max

// Assuming the existence of a namespace or class containing the constants and arrays
// For example, using a namespace named bt_data
namespace bt_data {
    // Assuming ce is a 2D array of doubles with dimensions 5x13
    extern double ce[5][13];
    extern double c1, c2, c3, c4, c5;
    extern double dnxm1, dnym1, dnzm1;
    extern double c1c2, c1c5, c3c4, c1345;
    extern double conz1;
    extern double tx1, tx2, tx3;
    extern double ty1, ty2, ty3;
    extern double tz1, tz2, tz3;
    extern double dx1, dx2, dx3, dx4, dx5;
    extern double dy1, dy2, dy3, dy4, dy5;
    extern double dz1, dz2, dz3, dz4, dz5;
    extern double dxmax, dymax, dzmax;
    extern double dssp;
    extern double c4dssp, c5dssp;
    extern double dttx1, dttx2;
    extern double dtty1, dtty2;
    extern double dttz1, dttz2;
    extern double c2dttx1, c2dtty1, c2dttz1;
    extern double dtdssp;
    extern double comz1, comz4, comz5, comz6;
    extern double c3c4tx3, c3c4ty3, c3c4tz3;
    extern double dx1tx1, dx2tx1, dx3tx1, dx4tx1, dx5tx1;
    extern double dy1ty1, dy2ty1, dy3ty1, dy4ty1, dy5ty1;
    extern double dz1tz1, dz2tz1, dz3tz1, dz4tz1, dz5tz1;
    extern double c2iv, con43, con16;
    extern double xxcon1, xxcon2, xxcon3, xxcon4, xxcon5;
    extern double yycon1, yycon2, yycon3, yycon4, yycon5;
    extern double zzcon1, zzcon2, zzcon3, zzcon4, zzcon5;
}

void set_constants() {
    using namespace bt_data;

    ce[0][0] = 2.0;
    ce[0][1] = 0.0;
    ce[0][2] = 0.0;
    ce[0][3] = 4.0;
    ce[0][4] = 5.0;
    ce[0][5] = 3.0;
    ce[0][6] = 0.5;
    ce[0][7] = 0.02;
    ce[0][8] = 0.01;
    ce[0][9] = 0.03;
    ce[0][10] = 0.5;
    ce[0][11] = 0.4;
    ce[0][12] = 0.3;

    ce[1][0] = 1.0;
    ce[1][1] = 0.0;
    ce[1][2] = 0.0;
    ce[1][3] = 0.0;
    ce[1][4] = 1.0;
    ce[1][5] = 2.0;
    ce[1][6] = 3.0;
    ce[1][7] = 0.01;
    ce[1][8] = 0.03;
    ce[1][9] = 0.02;
    ce[1][10] = 0.4;
    ce[1][11] = 0.3;
    ce[1][12] = 0.5;

    ce[2][0] = 2.0;
    ce[2][1] = 2.0;
    ce[2][2] = 0.0;
    ce[2][3] = 0.0;
    ce[2][4] = 0.0;
    ce[2][5] = 2.0;
    ce[2][6] = 3.0;
    ce[2][7] = 0.04;
    ce[2][8] = 0.03;
    ce[2][9] = 0.05;
    ce[2][10] = 0.3;
    ce[2][11] = 0.5;
    ce[2][12] = 0.4;

    ce[3][0] = 2.0;
    ce[3][1] = 2.0;
    ce[3][2] = 0.0;
    ce[3][3] = 0.0;
    ce[3][4] = 0.0;
    ce[3][5] = 2.0;
    ce[3][6] = 3.0;
    ce[3][7] = 0.03;
    ce[3][8] = 0.05;
    ce[3][9] = 0.04;
    ce[3][10] = 0.2;
    ce[3][11] = 0.1;
    ce[3][12] = 0.3;

    ce[4][0] = 5.0;
    ce[4][1] = 4.0;
    ce[4][2] = 3.0;
    ce[4][3] = 2.0;
    ce[4][4] = 0.1;
    ce[4][5] = 0.4;
    ce[4][6] = 0.3;
    ce[4][7] = 0.05;
    ce[4][8] = 0.04;
    ce[4][9] = 0.03;
    ce[4][10] = 0.1;
    ce[4][11] = 0.3;
    ce[4][12] = 0.2;

    c1 = 1.4;
    c2 = 0.4;
    c3 = 0.1;
    c4 = 1.0;
    c5 = 1.4;

    dnxm1 = 1.0 / static_cast<double>(grid_points[0] - 1);
    dnym1 = 1.0 / static_cast<double>(grid_points[1] - 1);
    dnzm1 = 1.0 / static_cast<double>(grid_points[2] - 1);

    c1c2 = c1 * c2;
    c1c5 = c1 * c5;
    c3c4 = c3 * c4;
    c1345 = c1c5 * c3c4;

    conz1 = (1.0 - c1c5);

    tx1 = 1.0 / (dnxm1 * dnxm1);
    tx2 = 1.0 / (2.0 * dnxm1);
    tx3 = 1.0 / dnxm1;

    ty1 = 1.0 / (dnym1 * dnym1);
    ty2 = 1.0 / (2.0 * dnym1);
    ty3 = 1.0 / dnym1;

    tz1 = 1.0 / (dnzm1 * dnzm1);
    tz2 = 1.0 / (2.0 * dnzm1);
    tz3 = 1.0 / dnzm1;

    dx1 = 0.75;
    dx2 = 0.75;
    dx3 = 0.75;
    dx4 = 0.75;
    dx5 = 0.75;

    dy1 = 0.75;
    dy2 = 0.75;
    dy3 = 0.75;
    dy4 = 0.75;
    dy5 = 0.75;

    dz1 = 1.0;
    dz2 = 1.0;
    dz3 = 1.0;
    dz4 = 1.0;
    dz5 = 1.0;

    dxmax = std::max(dx3, dx4);
    dymax = std::max(dy2, dy4);
    dzmax = std::max(dz2, dz3);

    dssp = 0.25 * std::max(dx1, std::max(dy1, dz1));