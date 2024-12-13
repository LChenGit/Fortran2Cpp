MODULE m
  IMPLICIT NONE

  TYPE t
  CONTAINS
    PROCEDURE, NOPASS, PRIVATE :: priv => proc
    PROCEDURE, NOPASS, PUBLIC :: publ => proc
  END TYPE t

CONTAINS

  SUBROUTINE proc ()
    PRINT *, "Procedure called"
  END SUBROUTINE proc

END MODULE m

PROGRAM test
  USE m
  IMPLICIT NONE
  TYPE(t) :: obj

  CALL obj%publ ()
  ! The private method call is not directly testable outside the module due to access control.
END PROGRAM test