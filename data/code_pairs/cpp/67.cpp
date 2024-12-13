#ifndef CHECKTRUECONTACT_H
#define CHECKTRUECONTACT_H

#include <vector>
#include <string>

void checkTrueContact(int ntie, const std::vector<std::string>& tieset, 
                      const std::vector<std::vector<double>>& tietol, 
                      const std::vector<std::vector<std::vector<double>>>& elcon, 
                      int& itruecontact, int ncmat_, int ntmat_);

#endif // CHECKTRUECONTACT_H