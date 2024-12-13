#include <vector>
#include <string>
#include <utility> // for std::pair

class ToxicityRelationships {
public:
    void addRelationship(const std::string& lessToxic, const std::string& moreToxic) {
        relationships.emplace_back(lessToxic, moreToxic);
    }

    bool isLessToxic(const std::string& substance1, const std::string& substance2) {
        for (const auto& relation : relationships) {
            if (relation.first == substance1 && relation.second == substance2) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::pair<std::string, std::string>> relationships;
};