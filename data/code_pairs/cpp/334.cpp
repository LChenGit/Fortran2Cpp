#include <iostream>
#include <vector>
#include <memory>

class TObjectList {
public:
    virtual std::vector<std::shared_ptr<TObjectList>> ArrayItem() = 0;
    virtual ~TObjectList() = default;
};

class TSampleList : public TObjectList {
public:
    std::vector<std::shared_ptr<TObjectList>> ArrayItem() override {
        std::cout << "ArrayItem called for TSampleList" << std::endl;
        return {};
    }

    void ConfidVal() {
        std::cout << "TSampleList_ConfidVal called" << std::endl;
    }
};