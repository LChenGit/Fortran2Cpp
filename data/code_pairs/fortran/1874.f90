! ELHEX27_TESTE__genmod.f90
MODULE ELHEX27_TESTE__genmod
  INTERFACE 
    SUBROUTINE ELHEX27_TESTE(NEL,KE,EL_DDISP,FINTE,INC)
      USE MOD_VARIABLES
      INTEGER(KIND=4) :: NEL
      REAL(KIND=8), INTENT(OUT) :: KE((P+1)*(Q+1)*(W+1)*NDS,(P+1)*(Q+1)*(W+1)*NDS)
      REAL(KIND=8), INTENT(IN) :: EL_DDISP((P+1)*(Q+1)*(W+1)*NDS,1)
      REAL(KIND=8), INTENT(OUT) :: FINTE((P+1)*(Q+1)*(W+1)*NDS,1)
      INTEGER(KIND=4) :: INC
    END SUBROUTINE ELHEX27_TESTE
  END INTERFACE 
END MODULE ELHEX27_TESTE__genmod

! MOD_VARIABLES.f90
MODULE MOD_VARIABLES
  INTEGER, PARAMETER :: P=2, Q=2, W=2, NDS=3
END MODULE

! test_ELHEX27_TESTE.f90
PROGRAM test_ELHEX27_TESTE
  USE ELHEX27_TESTE__genmod
  USE MOD_VARIABLES
  IMPLICIT NONE
  INTEGER :: NEL, INC
  INTEGER, PARAMETER :: dim = (P+1)*(Q+1)*(W+1)*NDS
  REAL(KIND=8), ALLOCATABLE :: KE(:,:), EL_DDISP(:,:), FINTE(:,:)

  NEL = 1
  INC = 1
  ALLOCATE(KE(dim,dim), EL_DDISP(dim,1), FINTE(dim,1))
  
  CALL ELHEX27_TESTE(NEL, KE, EL_DDISP, FINTE, INC)
  
  PRINT *, "FINTE:"
  PRINT *, FINTE

  DEALLOCATE(KE, EL_DDISP, FINTE)
END PROGRAM test_ELHEX27_TESTE