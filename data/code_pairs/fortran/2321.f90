PROGRAM TestILADLC
    IMPLICIT NONE
    INTEGER :: M, N, LDA, result
    DOUBLE PRECISION, DIMENSION(3, 4) :: A

    ! Initialize matrix A
    A = RESHAPE((/ 0.0D0, 0.0D0, 0.0D0, 0.0D0, &
                   0.0D0, 1.0D0, 0.0D0, 0.0D0, &
                   0.0D0, 0.0D0, 0.0D0, 0.0D0 /), (/3, 4/))

    ! Set the dimensions
    M = 3
    N = 4
    LDA = 3

    ! Call the function
    result = ILADLC(M, N, A, LDA)

    ! Print the result
    PRINT *, 'Result of ILADLC:', result

END PROGRAM TestILADLC

INTEGER FUNCTION ILADLC(M, N, A, LDA)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: M, N, LDA
    DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
    INTEGER I
    DOUBLE PRECISION ZERO
    PARAMETER (ZERO = 0.0D0)

    IF (N.EQ.0 .OR. A(1, N).NE.ZERO .OR. A(M, N).NE.ZERO) THEN
        ILADLC = N
    ELSE
        DO ILADLC = N, 1, -1
            DO I = 1, M
                IF (A(I, ILADLC).NE.ZERO) RETURN
            END DO
        END DO
    END IF
    RETURN
END FUNCTION ILADLC