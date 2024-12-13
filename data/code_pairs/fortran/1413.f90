MODULE math_operations
  IMPLICIT NONE
CONTAINS
  FUNCTION add(a, b)
    INTEGER, INTENT(IN) :: a, b
    INTEGER :: add
    add = a + b
  END FUNCTION add
END MODULE math_operations