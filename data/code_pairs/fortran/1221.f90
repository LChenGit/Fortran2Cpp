SUBROUTINE FRPLOT(N, S, X, HK, TH, UE, VE, XTR, FREF, XOFF, XSF, YOFF, YSF, CHF)
  IMPLICIT NONE
  INTEGER, INTENT(INOUT) :: N
  REAL, DIMENSION(N), INTENT(INOUT) :: S, X, HK, TH, UE, VE
  REAL, INTENT(INOUT) :: XTR, FREF, XOFF, XSF, YOFF, YSF
  CHARACTER, INTENT(INOUT) :: CHF
  
  N = 0
END SUBROUTINE FRPLOT

PROGRAM testFRPLOT
  IMPLICIT NONE
  INTEGER :: N
  REAL, ALLOCATABLE :: S(:), X(:), HK(:), TH(:), UE(:), VE(:)
  REAL :: XTR, FREF, XOFF, XSF, YOFF, YSF
  CHARACTER :: CHF
  
  N = 10
  ALLOCATE(S(N), X(N), HK(N), TH(N), UE(N), VE(N))
  
  CALL FRPLOT(N, S, X, HK, TH, UE, VE, XTR, FREF, XOFF, XSF, YOFF, YSF, CHF)
  
  IF (N == 0) THEN
    PRINT *, "Test passed: N is set to 0."
  ELSE
    PRINT *, "Test failed: N is not set to 0."
  END IF
END PROGRAM testFRPLOT