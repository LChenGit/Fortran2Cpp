#include <iostream>
#include <memory>

class TestModule {
public:
    class TestP;
    class Test;

    class TestP {
    private:
        std::shared_ptr<TestP> next;

    public:
        TestP() : next(nullptr) {}

        void setNext(const std::shared_ptr<TestP>& nextPtr) {
            this->next = nextPtr;
        }

        std::shared_ptr<TestP> getNext() const {
            return next;
        }
    };

    class Test {
    public:
        std::shared_ptr<Test> next;

        Test() : next(nullptr) {}
    };

    static void doIt(std::shared_ptr<TestP>& x) {
        x->setNext(x);
    }
};

int main() {
    std::shared_ptr<TestModule::TestP> x = std::make_shared<TestModule::TestP>();
    TestModule::doIt(x);

    if(x == x->getNext()) {
        std::cout << "Test passed: x->next is pointing to x." << std::endl;
    } else {
        std::cout << "Test failed: x->next is not pointing to x." << std::endl;
    }

    return 0;
}