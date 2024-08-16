MODULE COMPUTE_JACOBIAN_2D__genmod
    IMPLICIT NONE
    CONTAINS
    SUBROUTINE COMPUTE_JACOBIAN_2D(MYRANK, ISPECB, XELM, YELM, ZELM, &
                                   DERSHAPE2D, JACOBIAN2D, NORMAL, &
                                   NGLLA, NGLLB, NSPEC2DMAX_AB)
        INTEGER, INTENT(IN) :: MYRANK, ISPECB, NGLLA, NGLLB, NSPEC2DMAX_AB
        REAL(KIND=8), INTENT(IN) :: XELM(9), YELM(9), ZELM(9)
        REAL(KIND=8), INTENT(IN) :: DERSHAPE2D(2,9,NGLLA,NGLLB)
        REAL(KIND=4), INTENT(OUT) :: JACOBIAN2D(NGLLA,NGLLB,NSPEC2DMAX_AB)
        REAL(KIND=4), INTENT(OUT) :: NORMAL(3,NGLLA,NGLLB,NSPEC2DMAX_AB)

        ! Example computation
        JACOBIAN2D = 1.0
        NORMAL = 2.0
    END SUBROUTINE COMPUTE_JACOBIAN_2D
END MODULE COMPUTE_JACOBIAN_2D__genmod

PROGRAM test
    USE COMPUTE_JACOBIAN_2D__genmod
    IMPLICIT NONE
    INTEGER :: MYRANK, ISPECB, NGLLA, NGLLB, NSPEC2DMAX_AB
    REAL(KIND=8) :: XELM(9), YELM(9), ZELM(9)
    REAL(KIND=8) :: DERSHAPE2D(2,9,2,2)
    REAL(KIND=4) :: JACOBIAN2D(2,2,1)
    REAL(KIND=4) :: NORMAL(3,2,2,1)

    MYRANK = 0
    ISPECB = 1
    NGLLA = 2
    NGLLB = 2
    NSPEC2DMAX_AB = 1

    CALL COMPUTE_JACOBIAN_2D(MYRANK, ISPECB, XELM, YELM, ZELM, &
                             DERSHAPE2D, JACOBIAN2D, NORMAL, &
                             NGLLA, NGLLB, NSPEC2DMAX_AB)

    IF (ALL(JACOBIAN2D == 1.0) .AND. ALL(NORMAL == 2.0)) THEN
        PRINT *, "Fortran test passed."
    ELSE
        PRINT *, "Fortran test failed."
    END IF
END PROGRAM test