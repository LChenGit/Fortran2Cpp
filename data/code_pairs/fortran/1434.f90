REAL*8 FUNCTION func(x)
      REAL*8, INTENT(IN) :: x
      func = x * x
      END FUNCTION func

      SUBROUTINE GAULEG(X1,X2,X,W,N)
      IMPLICIT NONE
      REAL*8, INTENT(IN) :: X1, X2
      REAL*8, INTENT(OUT) :: X(N), W(N)
      REAL*8 :: EPS, XM, XL, Z, P1, P2, P3, PP, Z1
      INTEGER :: M, I, J
      PARAMETER (EPS=3.D-14)
      M=(N+1)/2
      XM=0.5D0*(X2+X1)
      XL=0.5D0*(X2-X1)
      DO I=1,M
          Z=COS(3.141592654D0*(I-.25D0)/(N+.5D0))
1         CONTINUE
              P1=1.D0
              P2=0.D0
              DO J=1,N
                  P3=P2
                  P2=P1
                  P1=((2.D0*J-1.D0)*Z*P2-(J-1.D0)*P3)/J
              END DO
              PP=N*(Z*P1-P2)/(Z*Z-1.D0)
              Z1=Z
              Z=Z1-P1/PP
              IF(ABS(Z-Z1).GT.EPS) GO TO 1
              X(I)=XM-XL*Z
              X(N+1-I)=XM+XL*Z
              W(I)=2.D0*XL/((1.D0-Z*Z)*PP*PP)
              W(N+1-I)=W(I)
      END DO
      END SUBROUTINE GAULEG

      PROGRAM TestGauleg
      IMPLICIT NONE
      REAL*8, ALLOCATABLE :: X(:), W(:)
      INTEGER :: N
      REAL*8 :: X1, X2
      
      N = 5
      X1 = 0.0
      X2 = 1.0
      ALLOCATE(X(N), W(N))
      
      CALL GAULEG(X1, X2, X, W, N)
      
      PRINT *, 'X:', X
      PRINT *, 'W:', W
      
      DEALLOCATE(X, W)
      END PROGRAM TestGauleg