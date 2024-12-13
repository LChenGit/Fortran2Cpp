#include <array>
#include <string>

class Isochrones {
public:
    static constexpr int niso = 9;
    static const std::array<std::string, niso> isofile;
};

const std::array<std::string, Isochrones::niso> Isochrones::isofile = {
    "isochrones/UBVRIJHKsKp/fehm25afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm20afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm15afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm10afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm05afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp00afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp02afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp03afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp05afep0.UBVRIJHKsKp"
};