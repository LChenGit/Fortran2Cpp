// types.h
#include <string>
#include <vector>

struct Person {
    std::string forename;
    int age;

    Person() : forename(""), age(0) {}
    Person(const std::string& name, int ageVal) : forename(name), age(ageVal) {}
};

enum class Color : int {
    red = 4,
    blue = 9,
    yellow // Automatically gets the value 10
};

class SolveInterface {
public:
    virtual std::vector<double> solve(int n, std::vector<double>& pmatrix, int key) = 0;
};

class SolveImpl : public SolveInterface {
public:
    std::vector<double> solve(int n, std::vector<double>& pmatrix, int key) override {
        std::vector<double> result;
        for (auto& val : pmatrix) {
            result.push_back(val * key);
        }
        return result;
    }
};