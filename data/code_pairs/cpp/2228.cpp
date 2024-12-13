#include <iostream>
#include <cassert>

const int max_aes = 100;  // Example value, replace with actual value from control_tables.inc
const int max_spac = 50;  // Example value, replace with actual value from control_tab_v1.inc

void enq_v1_teldef(int& nae_max, int& nsp_max, int& nba_max, int& nch_max, int s) {
    if (s != 0) return;

    nae_max = max_aes;
    nsp_max = max_spac;
    nba_max = 1;
    nch_max = 1;
}