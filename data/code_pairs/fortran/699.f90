! Define a module for our math operations
MODULE math_operations
  IMPLICIT NONE
CONTAINS
  ! Function to calculate the square of a number
  FUNCTION square(n) RESULT(res)
    INTEGER, INTENT(IN) :: n
    INTEGER :: res
    res = n*n
  END FUNCTION square
END MODULE math_operations

! Main program to test the square function
PROGRAM test_program
  USE math_operations
  IMPLICIT NONE
  INTEGER :: number, result
  
  ! Test the square function
  number = 4
  result = square(number)
  PRINT *, "The square of ", number, " is ", result
END PROGRAM test_program