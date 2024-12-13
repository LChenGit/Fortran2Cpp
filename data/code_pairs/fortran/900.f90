MODULE me08a_module
    IMPLICIT NONE
CONTAINS
    SUBROUTINE me08a(A, ALPHA, BETA, N, IA, Q)
        INTEGER, INTENT(IN) :: N, IA  
        COMPLEX, DIMENSION(IA,N), INTENT(INOUT) :: A 
        COMPLEX, DIMENSION(:), INTENT(IN) :: ALPHA 
        COMPLEX, DIMENSION(:), INTENT(INOUT) :: BETA       
        COMPLEX, DIMENSION(:), INTENT(INOUT) :: Q 

        INTEGER :: i, j
        DO i = 1, IA
            DO j = 1, N
                A(i,j) = A(i,j) * ALPHA(1)
            END DO
        END DO
        Q(1) = Q(1) + BETA(1)
    END SUBROUTINE me08a
END MODULE me08a_module