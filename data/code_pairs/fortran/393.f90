MODULE ASSEMBLYBBAR__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE ASSEMBLYBBAR(NZE, MA, MC, MV)
    INTEGER, INTENT(IN) :: NZE
    REAL(KIND=8), INTENT(IN) :: MA(:,:), MC(:,:), MV(:,:)
    REAL(KIND=8) :: sumMA, sumMC, sumMV
    sumMA = SUM(MA)
    sumMC = SUM(MC)
    sumMV = SUM(MV)
    PRINT *, "Sum of MA: ", sumMA
    PRINT *, "Sum of MC: ", sumMC
    PRINT *, "Sum of MV: ", sumMV
  END SUBROUTINE ASSEMBLYBBAR
END MODULE ASSEMBLYBBAR__genmod