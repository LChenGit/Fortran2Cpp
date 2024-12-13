! Assuming these are defined in separate modules or included before this definition
MODULE MOD_EOS_Vars
    IMPLICIT NONE
    REAL, PARAMETER :: mu0 = 1.0, Tref = 1.0, Ts = 2.0, ExpoSuth = 0.5, cSuth = 0.5
END MODULE MOD_EOS_Vars

MODULE MOD_Viscosity
    USE MOD_EOS_Vars
    IMPLICIT NONE
CONTAINS
    FUNCTION muSuth(T) RESULT(muSuthValue)
        REAL, INTENT(IN) :: T
        REAL :: muSuthValue
        REAL :: TnoDim
        TnoDim = T * Tref
        IF (TnoDim >= Ts) THEN
            muSuthValue = mu0 * TnoDim**ExpoSuth * (1 + Ts) / (TnoDim + Ts)
        ELSE
            muSuthValue = mu0 * TnoDim * cSuth
        END IF
    END FUNCTION muSuth
END MODULE MOD_Viscosity