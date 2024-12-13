#ifndef GREATRELATIONS_H
#define GREATRELATIONS_H

#include <vector>
#include <string>

struct Relationship {
    std::string from;
    std::string to;

    Relationship(std::string f, std::string t) : from(f), to(t) {}
};

class GreatRelations {
private:
    std::vector<Relationship> relationships;

public:
    GreatRelations() {
        relationships = {
            {"i1", "x1"},
            {"c1", "a1"},
            {"a1", "o1"},
            {"j1", "aa1"},
            {"h1", "l1"},
            // Add all other relationships here...
            {"z1", "g1"}
        };
    }

    bool checkRelationship(const std::string& from, const std::string& to) const {
        for (const auto& rel : relationships) {
            if (rel.from == from && rel.to == to) {
                return true;
            }
        }
        return false;
    }
};

#endif // GREATRELATIONS_H