MODULE DCOPY__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE DCOPY(N, DX, INCX, DY, INCY)
    INTEGER, INTENT(IN) :: N, INCX, INCY
    REAL(KIND=8), INTENT(IN) :: DX(*)
    REAL(KIND=8), INTENT(OUT) :: DY(*)
    INTEGER :: i, ix, iy
    
    ix = 1
    iy = 1
    DO i = 1, N
      DY(iy) = DX(ix)
      ix = ix + INCX
      iy = iy + INCY
    END DO
  END SUBROUTINE DCOPY
END MODULE DCOPY__genmod