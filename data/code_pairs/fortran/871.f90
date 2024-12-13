MODULE mod_tides
  IMPLICIT NONE
CONTAINS
  FUNCTION add_integers(a, b)
    INTEGER, INTENT(IN) :: a, b
    INTEGER :: add_integers
    add_integers = a + b
  END FUNCTION add_integers
END MODULE mod_tides