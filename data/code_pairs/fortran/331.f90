! Original Fortran Code
MODULE WAVModule
    IMPLICIT NONE
    INTEGER, PARAMETER :: BUFLEN = 8192, NBUFS = 10, NAMLEN = 500, NDESCR = 9
    INTEGER, PARAMETER :: DESLEN = 1, DESDAT = 2, DESDLN = 3, DESFMT = 4, 
    & DESFLN = 5, DESSAM = 6, DESCNS = 7, DESRTE = 8, DESBPS = 9
    CHARACTER(LEN=1) :: BUF(BUFLEN, NBUFS)
    INTEGER :: RECORD(2, NBUFS)
    INTEGER :: USED(NBUFS)
    LOGICAL :: DIRTY(NBUFS)
    LOGICAL :: FILEWR(0:99)
    INTEGER :: NXT
    INTEGER :: DESCR(NDESCR, 0:99)
    LOGICAL :: DTLAST(0:99)
    LOGICAL :: CHGWLN(0:99)
    LOGICAL :: CHGSAM(0:99)
END MODULE WAVModule

PROGRAM TestFortranCode
    USE WAVModule
    IMPLICIT NONE
    
    ! Unit test code for Fortran
    NXT = 1
    USED(1) = 1
    DIRTY(1) = .TRUE.
    FILEWR(0) = .TRUE.
    DESCR(DESLEN, 0) = 10
    DTLAST(0) = .FALSE.
    CHGWLN(0) = .TRUE.
    CHGSAM(0) = .FALSE.
    
    WRITE(*,*) 'Running Fortran unit tests...'
    IF (NXT == 1 .AND. USED(1) == 1 .AND. DIRTY(1) .AND. FILEWR(0) .AND. &
    DESCR(DESLEN, 0) == 10 .AND. .NOT. DTLAST(0) .AND. CHGWLN(0) .AND. .NOT. CHGSAM(0)) THEN
        WRITE(*,*) 'All Fortran tests passed.'
    ELSE
        WRITE(*,*) 'Some Fortran tests failed.'
    ENDIF
END PROGRAM TestFortranCode