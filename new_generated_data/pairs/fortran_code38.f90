PROGRAM ARE_CLOSE_TEST
    USE, INTRINSIC :: ISO_Fortran_env
    IMPLICIT NONE
    
    REAL(real64) :: a, b
    LOGICAL :: is_close
    
    a = 1.0d0
    b = 1.000001d0
    
    is_close = AreClose(a, b)
    
    IF (is_close) THEN
        PRINT *, "Numbers are close."
    ELSE
        PRINT *, "Numbers are not close."
    ENDIF
    
CONTAINS
    
    FUNCTION AreClose(a, b) RESULT(is_close)
        REAL(real64), INTENT(IN) :: a, b
        LOGICAL :: is_close
        REAL(real64), PARAMETER :: default_tolerance = TINY(1.0_real64)
        
        is_close = (ABS(a - b) <= default_tolerance * MAX(ABS(a), ABS(b)))
    END FUNCTION AreClose
    
END PROGRAM ARE_CLOSE_TEST