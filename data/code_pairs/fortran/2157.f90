MODULE BALANCE_COLORS_SIMPLE__genmod
  INTERFACE 
    SUBROUTINE BALANCE_COLORS_SIMPLE(IBOOL,IS_ON_A_SLICE_EDGE, &
     &ISPEC_IS_D,MYRANK,NSPEC,NGLOB,COLOR,NB_COLORS_OUTER_ELEMENTS,     &
     &NB_COLORS_INNER_ELEMENTS,NSPEC_OUTER,NSPEC_INNER,MASK_IBOOL)
      USE iso_fortran_env, ONLY: int32
      INTEGER(int32) :: NGLOB
      INTEGER(int32) :: NSPEC
      INTEGER(int32) :: IBOOL(5,5,5,NSPEC)
      LOGICAL :: IS_ON_A_SLICE_EDGE(NSPEC)
      LOGICAL :: ISPEC_IS_D(NSPEC)
      INTEGER(int32) :: MYRANK
      INTEGER(int32) :: COLOR(NSPEC)
      INTEGER(int32) :: NB_COLORS_OUTER_ELEMENTS
      INTEGER(int32) :: NB_COLORS_INNER_ELEMENTS
      INTEGER(int32) :: NSPEC_OUTER
      INTEGER(int32) :: NSPEC_INNER
      LOGICAL :: MASK_IBOOL(NGLOB)
    END SUBROUTINE BALANCE_COLORS_SIMPLE
  END INTERFACE 
END MODULE BALANCE_COLORS_SIMPLE__genmod

PROGRAM test_balance_colors_simple
  USE BALANCE_COLORS_SIMPLE__genmod
  IMPLICIT NONE

  INTEGER(int32) :: NGLOB, NSPEC, MYRANK
  INTEGER(int32) :: IBOOL(5,5,5,10)
  LOGICAL :: IS_ON_A_SLICE_EDGE(10)
  LOGICAL :: ISPEC_IS_D(10)
  INTEGER(int32) :: COLOR(10)
  INTEGER(int32) :: NB_COLORS_OUTER_ELEMENTS
  INTEGER(int32) :: NB_COLORS_INNER_ELEMENTS
  INTEGER(int32) :: NSPEC_OUTER
  INTEGER(int32) :: NSPEC_INNER
  LOGICAL :: MASK_IBOOL(10)

  ! Initialize variables
  NGLOB = 10
  NSPEC = 10
  MYRANK = 1
  NB_COLORS_OUTER_ELEMENTS = 2
  NB_COLORS_INNER_ELEMENTS = 3
  NSPEC_OUTER = 4
  NSPEC_INNER = 5
  
  ! Example initialization of arrays
  IBOOL = 1
  IS_ON_A_SLICE_EDGE = .TRUE.
  ISPEC_IS_D = .FALSE.
  COLOR = 0
  MASK_IBOOL = .TRUE.

  CALL BALANCE_COLORS_SIMPLE(IBOOL, IS_ON_A_SLICE_EDGE, ISPEC_IS_D, &
       MYRANK, NSPEC, NGLOB, COLOR, NB_COLORS_OUTER_ELEMENTS, &
       NB_COLORS_INNER_ELEMENTS, NSPEC_OUTER, NSPEC_INNER, MASK_IBOOL)

  PRINT *, 'COLOR = ', COLOR

END PROGRAM test_balance_colors_simple