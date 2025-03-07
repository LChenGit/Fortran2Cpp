MODULE tableb_mod
  INTERFACE
    SUBROUTINE TABLEB(X,Y,VER,SCALE,REFVAL,WIDTH,IFORMAT,NAME,UNIT)
      IMPLICIT NONE
      INTEGER         ,INTENT(IN)  :: X
      INTEGER         ,INTENT(IN)  :: Y
      INTEGER         ,INTENT(IN)  :: VER
      INTEGER         ,INTENT(OUT) :: SCALE
      INTEGER         ,INTENT(OUT) :: REFVAL
      INTEGER         ,INTENT(OUT) :: WIDTH
      CHARACTER(LEN=*),INTENT(OUT) :: IFORMAT
      CHARACTER(LEN=*),INTENT(OUT) :: NAME
      CHARACTER(LEN=*),INTENT(OUT) :: UNIT
    END SUBROUTINE TABLEB
  END INTERFACE
END MODULE tableb_mod

SUBROUTINE TABLEB(X,Y,VER,SCALE,REFVAL,WIDTH,IFORMAT,NAME,UNIT)
  IMPLICIT NONE
  INTEGER         ,INTENT(IN)  :: X
  INTEGER         ,INTENT(IN)  :: Y
  INTEGER         ,INTENT(IN)  :: VER
  INTEGER         ,INTENT(OUT) :: SCALE
  INTEGER         ,INTENT(OUT) :: REFVAL
  INTEGER         ,INTENT(OUT) :: WIDTH
  CHARACTER(LEN=*),INTENT(OUT) :: IFORMAT
  CHARACTER(LEN=*),INTENT(OUT) :: NAME
  CHARACTER(LEN=*),INTENT(OUT) :: UNIT
  
  SCALE = X + Y
  REFVAL = X - Y
  WIDTH = X * Y
  IFORMAT = 'Format-A'
  NAME = 'TestName'
  UNIT = 'Unit-X'
END SUBROUTINE TABLEB