MODULE t3dmix_mod
  IMPLICIT NONE
CONTAINS
  FUNCTION add_two_numbers(a, b)
    INTEGER, INTENT(IN) :: a, b
    INTEGER :: add_two_numbers
    add_two_numbers = a + b
  END FUNCTION add_two_numbers
END MODULE t3dmix_mod