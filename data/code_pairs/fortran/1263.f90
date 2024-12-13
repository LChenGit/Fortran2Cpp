SUBROUTINE SHGIVENS ( A,B, C,S)
      REAL A, B, C, S

      REAL AA, BB, R, U, V

      AA = A
      BB = B
      IF (ABS(AA) .LE. ABS(BB)) GO TO 1

      U = AA + AA
      V = BB/U
      IF (ABS(V) .LT. 1.E-25) V = 0.
      R = SQRT(.25 + V*V) * U
      C = AA/R
      S = V * (C + C)

      B = S
      A = R
      RETURN

    1 IF (BB .EQ. 0.) GO TO 2
      U = BB + BB
      V = AA/U

      IF (ABS(V) .LT. 1.E-25) V = 0.
      A = SQRT(.25 + V*V) * U
      S = BB/A
      C = V * (S + S)

      B = 1.
      IF (C .NE. 0.) B = 1./C
      RETURN

    2 C = 1.
      S = 0.
      RETURN
      END