PROGRAM TestFASA03
  IMPLICIT NONE

  DOUBLE PRECISION T, result

  ! External function declaration
  DOUBLE PRECISION iau_FASA03
  EXTERNAL iau_FASA03

  ! Test input value
  T = 0.5

  ! Call the function and print the result
  result = iau_FASA03(T)
  PRINT*, 'iau_FASA03(', T, ') = ', result

END PROGRAM TestFASA03

DOUBLE PRECISION FUNCTION iau_FASA03 ( T )
  IMPLICIT NONE
  DOUBLE PRECISION T
  DOUBLE PRECISION D2PI
  PARAMETER ( D2PI = 6.283185307179586476925287D0 )
  iau_FASA03 = MOD ( 0.874016757D0 + 21.3299104960D0 * T, D2PI )
END FUNCTION iau_FASA03