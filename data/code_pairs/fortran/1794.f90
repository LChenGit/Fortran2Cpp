! square_array.f90
SUBROUTINE squareArray(arr, n)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: n
    REAL, INTENT(INOUT) :: arr(n)
    INTEGER :: i

    DO i = 1, n
        arr(i) = arr(i)**2
    END DO
END SUBROUTINE squareArray