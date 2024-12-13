MODULE rotate_I
  USE, INTRINSIC :: iso_c_binding, ONLY: c_double
  IMPLICIT NONE

  INTERFACE
    SUBROUTINE rotate(NI, NJ, XI, XJ, W, KR, E1B, E2A, ENUC, CUTOF2)
      INTEGER, INTENT(IN) :: NI, NJ
      REAL(c_double), DIMENSION(3), INTENT(IN) :: XI, XJ
      REAL(c_double), DIMENSION(100), INTENT(OUT) :: W
      INTEGER, INTENT(INOUT) :: KR
      REAL(c_double), DIMENSION(10), INTENT(OUT) :: E1B, E2A
      REAL(c_double), INTENT(OUT) :: ENUC
      REAL(c_double), INTENT(IN) :: CUTOF2
    END SUBROUTINE rotate
  END INTERFACE

END MODULE rotate_I

PROGRAM main
  USE rotate_I
  IMPLICIT NONE

  INTEGER :: NI, NJ, KR
  REAL(c_double) :: CUTOF2
  REAL(c_double), DIMENSION(3) :: XI, XJ
  REAL(c_double), DIMENSION(100) :: W
  REAL(c_double), DIMENSION(10) :: E1B, E2A
  REAL(c_double) :: ENUC

  ! Initialize test values
  NI = 1
  NJ = 2
  KR = 0
  XI = [1.0_c_double, 2.0_c_double, 3.0_c_double]
  XJ = [4.0_c_double, 5.0_c_double, 6.0_c_double]
  CUTOF2 = 10.0_c_double

  ! Call the subroutine
  CALL rotate(NI, NJ, XI, XJ, W, KR, E1B, E2A, ENUC, CUTOF2)

  ! Output results
  PRINT *, "KR: ", KR
  PRINT *, "ENUC: ", ENUC

END PROGRAM main

SUBROUTINE rotate(NI, NJ, XI, XJ, W, KR, E1B, E2A, ENUC, CUTOF2)
  USE, INTRINSIC :: iso_c_binding, ONLY: c_double
  INTEGER, INTENT(IN) :: NI, NJ
  REAL(c_double), DIMENSION(3), INTENT(IN) :: XI, XJ
  REAL(c_double), DIMENSION(100), INTENT(OUT) :: W
  INTEGER, INTENT(INOUT) :: KR
  REAL(c_double), DIMENSION(10), INTENT(OUT) :: E1B, E2A
  REAL(c_double), INTENT(OUT) :: ENUC
  REAL(c_double), INTENT(IN) :: CUTOF2

  ! Implementation of rotate goes here
  ENUC = 123.456_c_double
  KR = KR + 1

END SUBROUTINE rotate