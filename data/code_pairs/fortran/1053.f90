MODULE mo_salsa_sizedist
  IMPLICIT NONE
CONTAINS
  SUBROUTINE size_distribution(kproma, kbdim, klev, n, dpg, sigmag, naero)
    INTEGER, INTENT(IN) :: kproma, kbdim, klev
    REAL(8), INTENT(IN) :: n(:), dpg(:), sigmag(:)
    REAL(8), INTENT(OUT) :: naero(kbdim, klev, kproma)
    INTEGER :: ii, jj, kk
    REAL(8) :: deltadp, pi6, pi
    pi = 3.141592653589793d0
    pi6 = 6.0d0 * pi
    naero = 0.0d0
    DO jj = 1, klev
      DO ii = 1, kbdim
        DO kk = 1, kproma
          deltadp = (kk**(1.0d0/3.0d0) - (kk-1)**(1.0d0/3.0d0)) / pi6**(1.0d0/3.0d0)
          naero(ii, jj, kk) = SUM(n * deltadp / (dpg * SQRT(2.0d0*pi) * LOG(sigmag)) * &
                                  EXP(-LOG(dpg/dpg(kk))**2 / (2.0d0*LOG(sigmag)**2)))
        END DO
      END DO
    END DO
  END SUBROUTINE size_distribution
END MODULE mo_salsa_sizedist