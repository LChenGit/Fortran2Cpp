#ifndef RECOVERC_H
#define RECOVERC_H

#include <vector>

void recoverC(int n1, int n2, const std::vector<float>& hlist, const std::vector<float>& dhlist,
              std::vector<std::vector<float>>& hbox, std::vector<std::vector<float>>& dhbox);

#endif