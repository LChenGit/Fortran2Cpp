MODULE daxpy_module
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE daxpy(N, DA, DX, INCX, DY, INCY)
      INTEGER, INTENT(IN) :: N
      REAL, INTENT(IN) :: DA
      REAL, DIMENSION(*), INTENT(IN) :: DX
      INTEGER, INTENT(IN) :: INCX
      REAL, DIMENSION(*), INTENT(INOUT) :: DY
      INTEGER, INTENT(IN) :: INCY
      INTEGER :: i

      DO i = 1, N, INCX
        DY(i) = DA * DX(i) + DY(i)
      END DO
    END SUBROUTINE daxpy
END MODULE daxpy_module