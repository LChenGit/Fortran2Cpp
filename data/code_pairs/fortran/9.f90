SUBROUTINE SROTG (SA, SB, SC, SS)
    REAL :: SA, SB, SC, SS
    REAL :: U, V, R

    IF (ABS(SA) > ABS(SB)) THEN
        U = SA + SA
        V = SB / U
        R = SQRT(0.25E0 + V**2) * U
        SC = SA / R
        SS = V * (SC + SC)
        SB = SS
        SA = R
    ELSE IF (SB /= 0.0E0) THEN
        U = SB + SB
        V = SA / U
        SA = SQRT(0.25E0 + V**2) * U
        SS = SB / SA
        SC = V * (SS + SS)
        IF (SC /= 0.0E0) THEN
            SB = 1.0E0 / SC
        ELSE
            SB = 1.0E0
        END IF
    ELSE
        SC = 1.0E0
        SS = 0.0E0
    END IF
END SUBROUTINE SROTG