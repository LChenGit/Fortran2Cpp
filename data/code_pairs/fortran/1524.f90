MODULE DataShadowingCombinations

  IMPLICIT NONE

  PUBLIC

  TYPE ShadowingCombinations
    LOGICAL :: UseThisSurf = .FALSE.
    INTEGER :: NumGenSurf = 0
    INTEGER, ALLOCATABLE, DIMENSION(:) :: GenSurf
    INTEGER :: NumBackSurf = 0
    INTEGER, ALLOCATABLE, DIMENSION(:) :: BackSurf
    INTEGER :: NumSubSurf = 0
    INTEGER, ALLOCATABLE, DIMENSION(:) :: SubSurf
  END TYPE ShadowingCombinations

  TYPE (ShadowingCombinations), ALLOCATABLE, DIMENSION(:) :: ShadowComb

END MODULE DataShadowingCombinations