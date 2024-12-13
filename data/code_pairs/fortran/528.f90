MODULE clawpack5_routines
    IMPLICIT NONE
    CONTAINS
    SUBROUTINE clawpack5_rpn2(ixy, maxm, meqn, mwaves, maux, mbc, &
         mx, ql, qr, auxl, auxr, wave, s, amdq, apdq)
        
        IMPLICIT NONE
        
        INTEGER, INTENT(IN) :: ixy, maxm, meqn, mwaves, maux, mbc, mx
        DOUBLE PRECISION, INTENT(IN) :: ql(meqn, 1-mbc:maxm+mbc), qr(meqn, 1-mbc:maxm+mbc)
        DOUBLE PRECISION, INTENT(IN) :: auxl(maux, 1-mbc:maxm+mbc), auxr(maux, 1-mbc:maxm+mbc)
        DOUBLE PRECISION, INTENT(OUT) :: wave(meqn, mwaves, 1-mbc:maxm+mbc)
        DOUBLE PRECISION, INTENT(OUT) :: s(mwaves, 1-mbc:maxm+mbc), amdq(meqn, 1-mbc:maxm+mbc), apdq(meqn, 1-mbc:maxm+mbc)
        
        INTEGER :: mu, mv, i
        DOUBLE PRECISION :: delta(3), a1, a2
        
        DOUBLE PRECISION :: rho, bulk, cc, zz
        
        rho = 1.0
        bulk = 1.0
        cc = 1.0
        zz = 1.0
        
        IF (ixy == 1) THEN
            mu = 2
            mv = 3
        ELSE
            mu = 3
            mv = 2
        ENDIF
        
        DO i = 2-mbc, mx+mbc
            delta(1) = ql(1,i) - qr(1,i-1)
            delta(2) = ql(mu,i) - qr(mu,i-1)
            a1 = (-delta(1) + zz*delta(2)) / (2.d0*zz)
            a2 = (delta(1) + zz*delta(2)) / (2.d0*zz)
            
            wave(1,1,i) = -a1*zz
            wave(mu,1,i) = a1
            wave(mv,1,i) = 0.d0
            s(1,i) = -cc
            
            wave(1,2,i) = a2*zz
            wave(mu,2,i) = a2
            wave(mv,2,i) = 0.d0
            s(2,i) = cc
        END DO
        
        DO i = 2-mbc, mx+mbc
            DO m = 1, meqn
                amdq(m,i) = s(1,i)*wave(m,1,i)
                apdq(m,i) = s(2,i)*wave(m,2,i)
            END DO
        END DO

    END SUBROUTINE clawpack5_rpn2
END MODULE clawpack5_routines

PROGRAM test_clawpack
    USE clawpack5_routines
    IMPLICIT NONE
    ! Define your test variables and call the subroutine here...
END PROGRAM test_clawpack