#include <string>

// Assuming global definitions are similar to those in the Fortran version
constexpr double zero = 0.0;

class cModel {
public:
    std::string name = "";
    virtual ~cModel() = default;
};

class cAngleModel : public cModel {
public:
    virtual void compute(double& Ea, double& Fa, double theta) = 0;
};

class angle_none : public cAngleModel {
public:
    void setup() {
        name = "none";
    }

    void compute(double& Ea, double& Fa, double theta) override {
        Ea = zero;
        Fa = zero;
    }
};