#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <memory>
#include <vector>

struct EleNumberingType {
    std::shared_ptr<std::vector<std::vector<int>>> number2count;
};

struct ElementType {
    std::shared_ptr<EleNumberingType> numbering;
};

class GlobalNumbering {
public:
    static std::vector<float> elementLocalCoords(const ElementType& element) {
        std::vector<float> coords(element.numbering->number2count->size(), 0.0f);
        return coords;
    }
};

#endif // ELEMENTS_HPP