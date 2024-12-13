MODULE H5T_PROVISIONAL
  IMPLICIT NONE
CONTAINS
  FUNCTION get_magic_number() RESULT(magic_number)
    INTEGER :: magic_number
    magic_number = 42
  END FUNCTION get_magic_number
END MODULE H5T_PROVISIONAL