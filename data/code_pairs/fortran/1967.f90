MODULE type_definitions
  TYPE :: type1
    INTEGER :: v
  END TYPE type1

  TYPE :: type2
    INTEGER :: v
  END TYPE type2

  TYPE :: type3
    INTEGER :: v
  END TYPE type3

  TYPE :: type4
    INTEGER :: v
  END TYPE type4
END MODULE type_definitions

PROGRAM MAIN
  USE type_definitions
  IMPLICIT NONE
  TYPE(type1) :: a
  TYPE(type2) :: b
  TYPE(type3) :: c
  TYPE(type4) :: d

  a%v = 1
  b%v = 2
  c%v = 3
  d%v = 4
  CALL test_type1(a)
  ! Assuming similar test subroutines for other types
END PROGRAM MAIN

CONTAINS

  SUBROUTINE test_type1(a)
    TYPE(type1), INTENT(IN) :: a
    IF (a%v == 1) THEN
      PRINT *, "test_type1 passed."
    ELSE
      PRINT *, "test_type1 failed."
    END IF
  END SUBROUTINE test_type1