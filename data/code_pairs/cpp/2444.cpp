#include <iostream>
#include <cassert>
#include <memory>

class LinkedNode {
public:
    int id = 0; // Adding ID for testing purpose as in Fortran code
    virtual ~LinkedNode() = default;
};

class BidirNode : public LinkedNode {
private:
    std::shared_ptr<BidirNode> prev;

public:
    BidirNode() : prev(nullptr) {}

    bool has_prev() const {
        return prev != nullptr;
    }

    std::shared_ptr<BidirNode> get_prev() const {
        return prev; // Direct return works due to smart pointers
    }

    void set_prev(const std::shared_ptr<BidirNode>& new_prev, bool deallocate_old = false) {
        if(deallocate_old && prev) {
            prev.reset(); // Implicit deallocation, custom logic might be needed for deep unset
        }
        prev = new_prev;
    }

    void unset_prev(bool deallocate_old = false) {
        if (deallocate_old && prev) {
            prev.reset(); // Implicit deallocation, custom logic might be needed for deep unset
        } else {
            prev.reset();
        }
    }
};

void test_bidir_node() {
    auto node1 = std::make_shared<BidirNode>();
    auto node2 = std::make_shared<BidirNode>();

    node1->id = 1;
    node2->id = 2;

    std::cout << "Node 1 ID: " << node1->id << std::endl;
    std::cout << "Node 2 ID: " << node2->id << std::endl;

    node1->set_prev(node2);
    std::cout << "Does Node 1 have a previous node? " << (node1->has_prev() ? "true" : "false") << std::endl;
    std::cout << "Node 1's previous node ID: " << node1->get_prev()->id << std::endl;

    node1->unset_prev();
    std::cout << "Does Node 1 have a previous node after unset? " << (node1->has_prev() ? "true" : "false") << std::endl;
}

int main() {
    test_bidir_node();
    return 0;
}