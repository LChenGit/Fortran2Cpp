MODULE types_module
  IMPLICIT NONE
  PUBLIC :: T, S

  TYPE :: T
    INTEGER :: A(2) = [1, 2]
  END TYPE T

  TYPE :: S
    INTEGER :: B = 1
  END TYPE S

END MODULE types_module