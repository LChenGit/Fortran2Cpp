MODULE DOT
    USE, INTRINSIC :: IEEE_ARITHMETIC
    IMPLICIT NONE

    LOGICAL :: MATRIX_ERROR = .FALSE.

CONTAINS

    REAL FUNCTION MULT(A,B)
        REAL, INTENT(IN) :: A(:),B(:)
        INTEGER :: I
        LOGICAL :: OVERFLOW
        MATRIX_ERROR = .FALSE.
        
        IF (SIZE(A)/=SIZE(B)) THEN
            MATRIX_ERROR = .TRUE.
            RETURN
        END IF
        
        MULT = 0.0
        DO I = 1, SIZE(A)
            MULT = MULT + A(I)*B(I)
        END DO
        
        CALL IEEE_GET_FLAG(IEEE_OVERFLOW, OVERFLOW)
        IF (OVERFLOW) MATRIX_ERROR = .TRUE.
    END FUNCTION MULT

END MODULE DOT