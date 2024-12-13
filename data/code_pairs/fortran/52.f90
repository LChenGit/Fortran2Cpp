MODULE mod_behavior
  IMPLICIT NONE
CONTAINS
  FUNCTION get_number() RESULT(number)
    INTEGER :: number
    number = 42
  END FUNCTION get_number
END MODULE mod_behavior