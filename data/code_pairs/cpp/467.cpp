#ifndef PPM_BEM_QUADRULE_HPP
#define PPM_BEM_QUADRULE_HPP

template<typename T>
class PpmBemQuadrule {
public:
    T quadrule() const {
        // Hypothetical calculation for demonstration
        if constexpr (std::is_same_v<T, float>) {
            return 1.0f; // Placeholder value for single precision
        } else {
            return 1.0; // Placeholder value for double precision
        }
    }
};

#endif // PPM_BEM_QUADRULE_HPP