MODULE mecid_I
  IMPLICIT NONE
  INTERFACE
    SUBROUTINE mecid(EIGS, GSE, EIGA, DIAG, XY)
      USE vast_kind_param, ONLY: DOUBLE
      INTEGER, PARAMETER :: nmos = 4
      REAL(DOUBLE), DIMENSION(*), INTENT(IN) :: EIGS
      REAL(DOUBLE), INTENT(OUT) :: GSE
      REAL(DOUBLE), DIMENSION(*), INTENT(INOUT) :: EIGA
      REAL(DOUBLE), DIMENSION(*), INTENT(OUT) :: DIAG
      REAL(DOUBLE), DIMENSION(nmos,nmos,nmos,nmos), INTENT(IN) :: XY
    END SUBROUTINE mecid
  END INTERFACE
END MODULE mecid_I

! vast_kind_param module (assuming DOUBLE is defined here)
MODULE vast_kind_param
  INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

! Implementation of the subroutine
SUBROUTINE mecid(EIGS, GSE, EIGA, DIAG, XY)
  USE vast_kind_param, ONLY: DOUBLE
  INTEGER, PARAMETER :: nmos = 4
  REAL(DOUBLE), DIMENSION(*), INTENT(IN) :: EIGS
  REAL(DOUBLE), INTENT(OUT) :: GSE
  REAL(DOUBLE), DIMENSION(*), INTENT(INOUT) :: EIGA
  REAL(DOUBLE), DIMENSION(*), INTENT(OUT) :: DIAG
  REAL(DOUBLE), DIMENSION(nmos,nmos,nmos,nmos), INTENT(IN) :: XY

  GSE = SUM(EIGS)
  EIGA = EIGA + 1.0_DOUBLE
  DIAG = EIGS * 2.0_DOUBLE
END SUBROUTINE mecid