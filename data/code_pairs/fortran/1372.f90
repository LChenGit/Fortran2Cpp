MODULE RD3DMODL__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE RD3DMODL(FILENAME, IERROR, NMODKERN, NHORPAR, ITYPHPAR, IHORPAR, LMAXHOR, NCOEFHOR, XLASPL, XLOSPL, XRASPL, IXLSPL, COEF, HSPLFILE, REFMODEL, KERNSTRI, DESCKERN)
    CHARACTER(LEN=*), INTENT(IN) :: FILENAME
    INTEGER, INTENT(INOUT) :: IERROR
    INTEGER, INTENT(IN) :: NMODKERN, NHORPAR
    INTEGER, DIMENSION(2), INTENT(IN) :: ITYPHPAR
    INTEGER, DIMENSION(200), INTENT(IN) :: IHORPAR
    INTEGER, DIMENSION(2), INTENT(IN) :: LMAXHOR
    INTEGER, DIMENSION(2), INTENT(IN) :: NCOEFHOR
    REAL, DIMENSION(2000,2), INTENT(IN) :: XLASPL, XLOSPL, XRASPL
    INTEGER, DIMENSION(2000,2), INTENT(IN) :: IXLSPL
    REAL, DIMENSION(2000,200), INTENT(IN) :: COEF
    CHARACTER(LEN=80), DIMENSION(2), INTENT(IN) :: HSPLFILE
    CHARACTER(LEN=80), INTENT(IN) :: REFMODEL, KERNSTRI
    CHARACTER(LEN=40), DIMENSION(200), INTENT(IN) :: DESCKERN
    
    PRINT *, "RD3DMODL subroutine called"
    IERROR = 0
  END SUBROUTINE RD3DMODL

END MODULE RD3DMODL__genmod