MODULE drotat_mod
    IMPLICIT NONE
    CONTAINS
    SUBROUTINE drotat(NI, XI, XJ, E1B, ENUC, RIJ)
        INTEGER, INTENT(IN) :: NI
        REAL(KIND=8), DIMENSION(3), INTENT(IN) :: XI, XJ
        REAL(KIND=8), DIMENSION(10), INTENT(OUT) :: E1B
        REAL(KIND=8), INTENT(OUT) :: ENUC
        REAL(KIND=8), INTENT(IN) :: RIJ
        
        ENUC = SUM(XI) + SUM(XJ)
        E1B = 10.0 * RIJ
    END SUBROUTINE drotat
END MODULE drotat_mod

PROGRAM test_drotat
    USE drotat_mod
    IMPLICIT NONE
    REAL(KIND=8), DIMENSION(3) :: XI = [1.0, 2.0, 3.0]
    REAL(KIND=8), DIMENSION(3) :: XJ = [4.0, 5.0, 6.0]
    REAL(KIND=8), DIMENSION(10) :: E1B
    REAL(KIND=8) :: ENUC
    REAL(KIND=8) :: RIJ = 2.0
    
    CALL drotat(3, XI, XJ, E1B, ENUC, RIJ)
    
    PRINT *, 'ENUC:', ENUC
    PRINT *, 'E1B:'
    PRINT *, E1B
END PROGRAM test_drotat