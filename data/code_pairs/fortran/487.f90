SUBROUTINE SLAE2( A, B, C, RT1, RT2 )
      IMPLICIT NONE
      REAL :: A, B, C, RT1, RT2
      REAL :: ONE, TWO, ZERO, HALF
      REAL :: AB, ACMN, ACMX, ADF, DF, RT, SM, TB
      PARAMETER (ONE = 1.0E0, TWO = 2.0E0, ZERO = 0.0E0, HALF = 0.5E0)
      
      SM = A + C
      DF = A - C
      ADF = ABS(DF)
      TB = B + B
      AB = ABS(TB)
      
      IF (ABS(A) > ABS(C)) THEN
         ACMX = A
         ACMN = C
      ELSE
         ACMX = C
         ACMN = A
      END IF
      
      IF (ADF > AB) THEN
         RT = ADF * SQRT(ONE + (AB / ADF)**2)
      ELSE IF (ADF < AB) THEN
         RT = AB * SQRT(ONE + (ADF / AB)**2)
      ELSE
         RT = AB * SQRT(TWO)
      END IF
      
      IF (SM < ZERO) THEN
         RT1 = HALF * (SM - RT)
         RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B
      ELSE IF (SM > ZERO) THEN
         RT1 = HALF * (SM + RT)
         RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B
      ELSE
         RT1 = HALF * RT
         RT2 = -HALF * RT
      END IF
END SUBROUTINE SLAE2

PROGRAM TestSLAE2
      REAL :: A, B, C, RT1, RT2
      
      A = 2.0
      B = -3.0
      C = 1.0
      CALL SLAE2(A, B, C, RT1, RT2)
      PRINT *, "Test Case 1: RT1 = ", RT1, "RT2 = ", RT2
END PROGRAM TestSLAE2