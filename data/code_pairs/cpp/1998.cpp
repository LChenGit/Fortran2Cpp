#include <vector>
#include <algorithm>

class SoopStars {
public:
    std::vector<float> position, velocity;

    SoopStars() = default;
    SoopStars(const std::vector<float>& pos, const std::vector<float>& vel) : position(pos), velocity(vel) {}

    SoopStars operator+(const SoopStars& rhs) const {
        std::vector<float> newPos(position.size()), newVel(velocity.size());
        std::transform(position.begin(), position.end(), rhs.position.begin(), newPos.begin(), std::plus<>());
        std::transform(velocity.begin(), velocity.end(), rhs.velocity.begin(), newVel.begin(), std::plus<>());
        return {newPos, newVel};
    }

    SoopStars operator*(float rhs) const {
        std::vector<float> newPos(position.size()), newVel(velocity.size());
        std::transform(position.begin(), position.end(), newPos.begin(), [rhs](float val) { return val * rhs; });
        std::transform(velocity.begin(), velocity.end(), newVel.begin(), [rhs](float val) { return val * rhs; });
        return {newPos, newVel};
    }
};