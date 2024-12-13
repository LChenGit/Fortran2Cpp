#ifndef IUSERINTERFACE_H
#define IUSERINTERFACE_H

#include <vector>

class IUserInterface {
public:
    virtual void evalf(int n, const std::vector<double>& x, double& f, int& flag) = 0;
    virtual void evalc(int n, const std::vector<double>& x, int ind, double& c, int& flag) = 0;
    virtual void evaljac(int n, const std::vector<double>& x, int ind, std::vector<int>& jcvar, std::vector<double>& jcval, int& jcnnz, int& flag) = 0;
    virtual ~IUserInterface() = default;
};

#endif