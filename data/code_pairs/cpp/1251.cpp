#ifndef GREAT_H
#define GREAT_H

#include <vector>
#include <string>
#include <utility>

class GreatRelationships {
public:
    void great(const std::string& entity1, const std::string& entity2) {
        relationships.emplace_back(entity1, entity2);
    }

    void printRelationships() const {
        std::cout << "Testing relationships:" << std::endl;
        for (const auto& relationship : relationships) {
            std::cout << relationship.first << " -> " << relationship.second << std::endl;
        }
    }

private:
    std::vector<std::pair<std::string, std::string>> relationships;
};

#endif // GREAT_H