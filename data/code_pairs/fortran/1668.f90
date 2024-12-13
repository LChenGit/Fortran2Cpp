PROGRAM TestSCABS1
      COMPLEX Z
      REAL SCABS1

      ! Test cases
      Z = CMPLX(3.0, 4.0)
      PRINT *, 'SCABS1(3+4i) =', SCABS1(Z)

      Z = CMPLX(-5.0, -12.0)
      PRINT *, 'SCABS1(-5-12i) =', SCABS1(Z)

      END

      REAL FUNCTION SCABS1(Z)
      COMPLEX Z
      INTRINSIC ABS,AIMAG,REAL
      SCABS1 = ABS(REAL(Z)) + ABS(AIMAG(Z))
      RETURN
      END