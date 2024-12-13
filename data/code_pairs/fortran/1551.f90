! file: arc_functions.f90
SUBROUTINE ARCDABS (R, X)
    REAL, INTENT(OUT) :: R
    REAL, INTENT(IN) :: X
    R = ABS(X)
END SUBROUTINE ARCDABS

SUBROUTINE ARCXDABS (R, X)
    REAL, INTENT(OUT) :: R
    COMPLEX, INTENT(IN) :: X
    R = ABS(X)
END SUBROUTINE ARCXDABS

PROGRAM testArcFunctions
    REAL :: rReal
    COMPLEX :: testValueComplex = (3.0, 4.0)

    CALL ARCDABS(rReal, -4.0)
    PRINT *, 'ARCDABS(-4.0) = ', rReal

    CALL ARCXDABS(rReal, testValueComplex)
    PRINT *, 'ARCXDABS((3.0, 4.0)) = ', rReal
END PROGRAM testArcFunctions