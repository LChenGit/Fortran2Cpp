SUBROUTINE ZLAR2V( N, X, Y, Z, INCX, C, S, INCC )
      INTEGER            INCC, INCX, N
      DOUBLE PRECISION   C( * )
      COMPLEX*16         S( * ), X( * ), Y( * ), Z( * )
      INTEGER            I, IC, IX
      DOUBLE PRECISION   CI, SII, SIR, T1I, T1R, T5, T6, XI, YI, ZII, ZIR
      COMPLEX*16         SI, T2, T3, T4, ZI
      INTRINSIC          DBLE, DCMPLX, DCONJG, DIMAG

      IX = 1
      IC = 1
      DO I = 1, N
         XI = DBLE( X( IX ) )
         YI = DBLE( Y( IX ) )
         ZI = Z( IX )
         ZIR = DBLE( ZI )
         ZII = DIMAG( ZI )
         CI = C( IC )
         SI = S( IC )
         SIR = DBLE( SI )
         SII = DIMAG( SI )
         T1R = SIR*ZIR - SII*ZII
         T1I = SIR*ZII + SII*ZIR
         T2 = CI*ZI
         T3 = T2 - DCONJG( SI )*XI
         T4 = DCONJG( T2 ) + SI*YI
         T5 = CI*XI + T1R
         T6 = CI*YI - T1R
         X( IX ) = CI*T5 + ( SIR*DBLE( T4 ) + SII*DIMAG( T4 ) )
         Y( IX ) = CI*T6 - ( SIR*DBLE( T3 ) - SII*DIMAG( T3 ) )
         Z( IX ) = CI*T3 + DCONJG( SI )*DCMPLX( T6, T1I )
         IX = IX + INCX
         IC = IC + INCC
      END DO
      RETURN
      END