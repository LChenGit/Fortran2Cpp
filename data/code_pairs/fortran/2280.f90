PROGRAM main
  IMPLICIT NONE
  TYPE :: test_typ
    REAL :: a
  END TYPE
  TYPE(test_typ) :: my_test_typ
  my_test_typ%a = 1.0
  IF (ABS(my_test_typ%a - 1.0) > 1e-6) STOP 1
END PROGRAM main