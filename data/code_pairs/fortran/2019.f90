MODULE PolyFunctions
    IMPLICIT NONE
CONTAINS
    REAL FUNCTION FPOLY(NDEG, COEFF, X)
        INTEGER, INTENT(IN) :: NDEG
        REAL, INTENT(IN) :: COEFF(NDEG+1)
        REAL, INTENT(IN) :: X
        INTEGER :: K
        DOUBLE PRECISION :: DSUM
        DSUM = DBLE(COEFF(NDEG+1))
        IF (NDEG > 0) THEN
            DO K = NDEG, 1, -1
                DSUM = DSUM * DBLE(X) + DBLE(COEFF(K))
            END DO
        END IF
        FPOLY = REAL(DSUM)
    END FUNCTION FPOLY
END MODULE PolyFunctions