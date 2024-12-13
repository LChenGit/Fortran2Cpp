MODULE vast_kind_param
    INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

MODULE etrbk3_I
    USE vast_kind_param, ONLY: DOUBLE
    CONTAINS
        SUBROUTINE etrbk3 (NM, N, NV, A, M, Z) 
            INTEGER, INTENT(IN) :: NM, N, NV, M
            REAL(DOUBLE), DIMENSION(NV), INTENT(IN) :: A
            REAL(DOUBLE), DIMENSION(NM,M) :: Z

            INTEGER :: I
            IF (NV <= M) THEN
                DO I = 1, NV
                    Z(1, I) = A(I)
                END DO
            END IF
        END SUBROUTINE etrbk3
END MODULE etrbk3_I