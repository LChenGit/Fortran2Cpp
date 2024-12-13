SUBROUTINE CLAPMT(FORWRD, M, N, X, LDX, K)
    LOGICAL            FORWRD
    INTEGER            LDX, M, N
    INTEGER            K(*)
    COMPLEX            X(LDX,*)

    INTEGER            I, II, J, IN
    COMPLEX            TEMP

    IF (N.LE.1) RETURN

    DO I = 1, N
        K(I) = -K(I)
    END DO

    IF (FORWRD) THEN
        DO I = 1, N
            IF (K(I) > 0) GO TO 40

            J = I
            K(J) = -K(J)
            IN = K(J)

            DO WHILE (K(IN) <= 0)
                DO II = 1, M
                    TEMP = X(II, J)
                    X(II, J) = X(II, IN)
                    X(II, IN) = TEMP
                END DO
                K(IN) = -K(IN)
                J = IN
                IN = K(IN)
            END DO
40          CONTINUE
        END DO
    ELSE
        DO I = 1, N
            IF (K(I) > 0) GO TO 100

            K(I) = -K(I)
            J = K(I)
            DO WHILE (J /= I)
                DO II = 1, M
                    TEMP = X(II, I)
                    X(II, I) = X(II, J)
                    X(II, J) = TEMP
                END DO
                K(J) = -K(J)
                J = K(J)
            END DO
100     CONTINUE
        END DO
    END IF
END SUBROUTINE CLAPMT