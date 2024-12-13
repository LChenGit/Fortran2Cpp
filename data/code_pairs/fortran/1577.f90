MODULE MEANFLUXES__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE MEANFLUXES(fluxes, n, mean_flux)
    REAL, INTENT(IN) :: fluxes(:)
    INTEGER, INTENT(IN) :: n
    REAL, INTENT(OUT) :: mean_flux
    mean_flux = SUM(fluxes) / REAL(n)
  END SUBROUTINE MEANFLUXES
END MODULE MEANFLUXES__genmod