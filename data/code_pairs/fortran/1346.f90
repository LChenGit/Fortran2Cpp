MODULE BUFRQEL_mod
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE BUFRQEL(STRING,CMPRES,LASTEL,LASBIT,N,NEXBIT,    &
     SCALE,WIDTH,REFVAL,FORMAT,DESCR,NLOG,IRC)
      CHARACTER(LEN=*), INTENT(IN)     :: STRING
      LOGICAL,          INTENT(IN)     :: CMPRES
      INTEGER,          INTENT(IN)     :: LASTEL
      INTEGER,          INTENT(IN)     :: LASBIT
      INTEGER,          INTENT(IN)     :: N
      INTEGER,          INTENT(INOUT)  :: NEXBIT
      INTEGER,          INTENT(INOUT)  :: SCALE
      INTEGER,          INTENT(INOUT)  :: WIDTH
      INTEGER,          INTENT(INOUT)  :: REFVAL
      CHARACTER(LEN=1), INTENT(INOUT)  :: FORMAT
      INTEGER,          INTENT(INOUT)  :: DESCR(*)
      INTEGER,          INTENT(INOUT)  :: NLOG
      INTEGER,          INTENT(OUT)    :: IRC
      
      ! Example implementation
      IRC = 0
      PRINT *, 'BUFRQEL called successfully.'
    END SUBROUTINE BUFRQEL
END MODULE BUFRQEL_mod