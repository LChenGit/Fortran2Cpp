PROGRAM TestLAGZO
    IMPLICIT NONE
    INTEGER, PARAMETER :: n = 5
    DOUBLE PRECISION :: X(n), W(n)
    INTEGER :: i

    CALL LAGZO(n, X, W)

    PRINT *, 'X:', (X(i), i = 1, n)
    PRINT *, 'W:', (W(i), i = 1, n)

CONTAINS

    SUBROUTINE LAGZO(N, X, W)
        IMPLICIT DOUBLE PRECISION (A-H, O-Z)
        INTEGER :: N, NR, IT, I, K, J
        DOUBLE PRECISION :: X(N), W(N), HN, Z, Z0, P, F0, F1, PF, PD, FD, Q, WP, GD
        HN = 1.0D0 / N
        DO NR = 1, N
            IF (NR .EQ. 1) THEN
                Z = HN
            ELSE
                Z = X(NR-1) + HN * NR**1.27
            END IF
            IT = 0
1           CONTINUE
            IT = IT + 1
            Z0 = Z
            P = 1.0D0
            DO I = 1, NR-1
                P = P * (Z - X(I))
            END DO
            F0 = 1.0D0
            F1 = 1.0D0 - Z
            DO K = 2, N
                PF = ((2.0D0*K - 1.0D0 - Z) * F1 - (K - 1.0D0) * F0) / K
                PD = K / Z * (PF - F1)
                F0 = F1
                F1 = PF
            END DO
            FD = F1 / P
            Q = 0.0D0
            DO I = 1, NR-1
                WP = 1.0D0
                DO J = 1, NR-1
                    IF (J .NE. I) THEN
                        WP = WP * (Z - X(J))
                    END IF
                END DO
                Q = Q + WP
            END DO
            GD = (PD - Q * FD) / P
            Z = Z - FD / GD
            IF (IT .LE. 40 .AND. ABS((Z - Z0) / Z) > 1.0D-15) THEN
                GOTO 1
            END IF
            X(NR) = Z
            W(NR) = 1.0D0 / (Z * PD * PD)
        END DO
    END SUBROUTINE LAGZO
END PROGRAM TestLAGZO