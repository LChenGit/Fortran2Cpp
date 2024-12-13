SUBROUTINE SUBTRACT_MEAN_3D(A_IN, MAXX_IN, MAXY_IN, MAXZ_IN, NX, NY, NZ,
     $BADDATA, MAXX_OUT, MAXY_OUT, MAXZ_OUT, A_OUT)
      IMPLICIT NONE
      INTEGER::MAXX_IN, MAXY_IN, MAXZ_IN,
     $MAXX_OUT, MAXY_OUT, MAXZ_OUT,
     $NX, NY, NZ, IX, IY, IZ,
     $COUNT
      REAL BADDATA,
     $SUM, MEAN
      REAL A_IN(MAXX_IN, MAXY_IN, MAXZ_IN)
      REAL A_OUT(MAXX_OUT, MAXY_OUT, MAXZ_OUT)
      SUM=0.
      COUNT=0
      DO IZ=1,NZ
         DO IY=1,NY
            DO IX=1,NX
               IF(A_IN(IX,IY,IZ).NE.BADDATA)THEN
                  SUM=SUM+A_IN(IX,IY,IZ)
                  COUNT=COUNT+1
               ENDIF
            ENDDO
         ENDDO
      ENDDO
      IF(COUNT.NE.0)THEN
         MEAN=SUM/FLOAT(COUNT)
      ELSE
         MEAN=0.0
      ENDIF
      DO IZ=1,NZ
         DO IY=1,NY
            DO IX=1,NX
               IF(A_IN(IX,IY,IZ).NE.BADDATA)THEN
                  A_OUT(IX,IY,IZ)=A_IN(IX,IY,IZ)-MEAN
               ELSE
                  A_OUT(IX,IY,IZ)=BADDATA
               ENDIF
            ENDDO
         ENDDO
      ENDDO
END