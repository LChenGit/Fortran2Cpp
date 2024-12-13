SUBROUTINE FIND(ibuffer, ib, nini, ntot, ip, iat)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: ibuffer(*), ib, nini, ntot, ip
    INTEGER, INTENT(OUT) :: iat
    INTEGER :: ipx, i

    ipx = 0
    iat = 0
    DO i = nini+1, ntot
        IF (ibuffer(i) == ib) THEN
            ipx = ipx + 1
            IF (ip == ipx) THEN
                iat = i
                RETURN
            END IF
        END IF
    END DO
END SUBROUTINE FIND