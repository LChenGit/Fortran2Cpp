LOGICAL          FUNCTION DLCTES( ZR, ZI, D )
      DOUBLE PRECISION   D, ZI, ZR
      DOUBLE PRECISION   ZERO, ONE
      PARAMETER          ( ZERO = 0.0D+0, ONE = 1.0D+0 )
      INTRINSIC          SIGN
      IF( D.EQ.ZERO ) THEN
         DLCTES = ( ZR.LT.ZERO )
      ELSE
         DLCTES = ( SIGN( ONE, ZR ).NE.SIGN( ONE, D ) )
      END IF
      RETURN
      END