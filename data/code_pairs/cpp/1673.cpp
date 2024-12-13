#include <memory>

class Node {
public:
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
    Node(const Node& other) = delete; // prevent copy construction
    Node& operator=(const Node& other) = delete; // prevent copy assignment
    ~Node() = default;

    friend std::unique_ptr<Node> add_nodes(const Node& node1, const Node& node2);
};

std::unique_ptr<Node> add_nodes(const Node& node1, const Node& node2) {
    return std::make_unique<Node>(node1.data + node2.data);
}