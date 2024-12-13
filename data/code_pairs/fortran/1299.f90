! This Fortran program includes a simple function for adding two integers.
MODULE MathOperations
  IMPLICIT NONE
CONTAINS
  INTEGER FUNCTION add(a, b)
    INTEGER, INTENT(IN) :: a, b
    add = a + b
  END FUNCTION add
END MODULE MathOperations

PROGRAM MAIN
  USE MathOperations
  IMPLICIT NONE
  PRINT *, add(2, 3)  ! This will print the result of adding 2 and 3
END PROGRAM MAIN