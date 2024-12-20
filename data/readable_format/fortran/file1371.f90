MODULE RD3DMODL__genmod
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE RD3DMODL(FILENAME,IERROR,NMODKERN,NHORPAR,       &
    &ITYPHPAR,IHORPAR,LMAXHOR,NCOEFHOR,XLASPL,XLOSPL,XRASPL,IXLSPL,COEF&
    &,HSPLFILE,REFMODEL,KERNSTRI,DESCKERN)
      CHARACTER(LEN=128), INTENT(IN) :: FILENAME
      INTEGER(KIND=4), INTENT(INOUT) :: IERROR
      INTEGER(KIND=4) :: NMODKERN
      INTEGER(KIND=4) :: NHORPAR
      INTEGER(KIND=4), DIMENSION(2) :: ITYPHPAR
      INTEGER(KIND=4), DIMENSION(200) :: IHORPAR
      INTEGER(KIND=4), DIMENSION(2) :: LMAXHOR
      INTEGER(KIND=4), DIMENSION(2) :: NCOEFHOR
      REAL(KIND=4), DIMENSION(2000,2) :: XLASPL
      REAL(KIND=4), DIMENSION(2000,2) :: XLOSPL
      REAL(KIND=4), DIMENSION(2000,2) :: XRASPL
      INTEGER(KIND=4), DIMENSION(2000,2) :: IXLSPL
      REAL(KIND=4), DIMENSION(2000,200) :: COEF
      CHARACTER(LEN=80), DIMENSION(2) :: HSPLFILE
      CHARACTER(LEN=80) :: REFMODEL
      CHARACTER(LEN=80) :: KERNSTRI
      CHARACTER(LEN=40), DIMENSION(200) :: DESCKERN

      ! Dummy implementation for compilation
      IERROR = 0
      PRINT *, "RD3DMODL subroutine called"
    END SUBROUTINE RD3DMODL
END MODULE RD3DMODL__genmod

PROGRAM test_program
  USE RD3DMODL__genmod
  IMPLICIT NONE

  CHARACTER(LEN=128) :: FILENAME
  INTEGER(KIND=4) :: IERROR
  INTEGER(KIND=4) :: NMODKERN, NHORPAR
  INTEGER(KIND=4), DIMENSION(2) :: ITYPHPAR
  INTEGER(KIND=4), DIMENSION(200) :: IHORPAR
  INTEGER(KIND=4), DIMENSION(2) :: LMAXHOR
  INTEGER(KIND=4), DIMENSION(2) :: NCOEFHOR
  REAL(KIND=4), DIMENSION(2000,2) :: XLASPL, XLOSPL, XRASPL
  INTEGER(KIND=4), DIMENSION(2000,2) :: IXLSPL
  REAL(KIND=4), DIMENSION(2000,200) :: COEF
  CHARACTER(LEN=80), DIMENSION(2) :: HSPLFILE
  CHARACTER(LEN=80) :: REFMODEL, KERNSTRI
  CHARACTER(LEN=40), DIMENSION(200) :: DESCKERN

  ! Initialize variables as needed
  FILENAME = 'test_input.txt'  ! Make sure this file exists or adjust as needed
  IERROR = 0
  NMODKERN = 1
  NHORPAR = 2
  ITYPHPAR = (/1, 2/)
  ! Initialize other variables as needed...

  CALL RD3DMODL(FILENAME, IERROR, NMODKERN, NHORPAR, ITYPHPAR, IHORPAR, LMAXHOR, &
      &NCOEFHOR, XLASPL, XLOSPL, XRASPL, IXLSPL, COEF, HSPLFILE, REFMODEL, KERNSTRI, &
      &DESCKERN)

  IF (IERROR == 0) THEN
    PRINT *, "RD3DMODL executed successfully."
  ELSE
    PRINT *, "RD3DMODL execution failed."
  END IF
END PROGRAM test_program