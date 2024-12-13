MODULE hmixing_mod
  IMPLICIT NONE
  CONTAINS
    FUNCTION add_numbers(a, b)
      INTEGER, INTENT(IN) :: a, b
      INTEGER :: add_numbers
      
      add_numbers = a + b
    END FUNCTION add_numbers
END MODULE hmixing_mod