#ifndef TFANIMAL_H
#define TFANIMAL_H

#include <string>

class TFAnimal {
public:
    virtual std::string say() const = 0;
    virtual ~TFAnimal() = default;
};

#endif // TFANIMAL_H