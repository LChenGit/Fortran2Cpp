MODULE dropdep_var
    IMPLICIT NONE
    PRIVATE
    PUBLIC :: r, chr1, pi
    INTEGER, PARAMETER :: pi = 5
    INTEGER, PARAMETER :: dp = KIND(1.D0)
    REAL(KIND=dp) :: r
    CHARACTER(LEN=pi) :: chr1
END MODULE dropdep_var