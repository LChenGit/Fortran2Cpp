MODULE CLASWP_MOD
  IMPLICIT NONE
CONTAINS
  SUBROUTINE CLASWP(N, A, LDA, K1, K2, IPIV, INCX)
    INTEGER, INTENT(IN) :: N, LDA, K1, K2, INCX
    INTEGER, INTENT(IN) :: IPIV(*)
    COMPLEX, INTENT(INOUT) :: A(LDA, *)
    INTEGER :: I, J, IX, IP
    COMPLEX :: TEMP

    IF (INCX > 0) THEN
        IX = K1
    ELSE IF (INCX < 0) THEN
        IX = 1 + (1 - K2) * INCX
    ELSE
        RETURN
    END IF

    DO J = 1, N
      DO I = K1, K2
        IP = IPIV(IX)
        IF (IP /= I) THEN
          DO IX = 1, LDA
            TEMP = A(IX, I)
            A(IX, I) = A(IX, IP)
            A(IX, IP) = TEMP
          END DO
        END IF
        IX = IX + INCX
      END DO
    END DO

  END SUBROUTINE CLASWP
END MODULE CLASWP_MOD

PROGRAM test_claswp
  USE CLASWP_MOD
  IMPLICIT NONE
  COMPLEX, ALLOCATABLE :: A(:,:)
  INTEGER, ALLOCATABLE :: IPIV(:)
  INTEGER :: N, LDA, K1, K2, INCX, I, J

  N = 5
  LDA = 5
  K1 = 1
  K2 = 5
  INCX = 1

  ALLOCATE(A(LDA,N), IPIV(K2))

  DO I = 1, LDA
    DO J = 1, N
      A(I,J) = COMPLEX(I, J)
    END DO
  END DO

  ! Set up a specific pivot to see the effect
  DO I = K1, K2
    IPIV(I) = K2 + 1 - I
  END DO

  PRINT *, 'Before CLASWP:'
  DO I = 1, LDA
    PRINT '(*(F4.0, ", ", F4.0, " "))', A(:, I)
  END DO

  CALL CLASWP(N, A, LDA, K1, K2, IPIV, INCX)

  PRINT *, 'After CLASWP:'
  DO I = 1, LDA
    PRINT '(*(F4.0, ", ", F4.0, " "))', A(:, I)
  END DO

  DEALLOCATE(A, IPIV)
END PROGRAM test_claswp