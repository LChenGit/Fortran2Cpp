! Define the FSCAN subroutine
SUBROUTINE FSCAN (OPCODE, NLC, NLI, NLD, NLCPRM, NLIPRM, NLDPRM, WORLD, PIXEL, CONTRL, CONTXT, IERR)
  INTEGER   CONTRL, IERR, NLC, NLD, NLI, NLIPRM(NLI), OPCODE
  DOUBLE PRECISION CONTXT(20), NLDPRM(NLD), PIXEL(2), S, WORLD(2)
  CHARACTER NLCPRM(NLC)*1
  IERR = 0

  IF (OPCODE.GT.0) THEN
    PIXEL(1) =  NLDPRM(1) + (WORLD(1) - NLDPRM(3))/NLDPRM(5)
    S =  NLDPRM(4) + PIXEL(1)*NLDPRM(7)
    PIXEL(2) =  NLDPRM(2) + (WORLD(2) - S)/NLDPRM(6)

    CONTRL = 0

  ELSE IF (OPCODE.EQ.0) THEN
    IF (NLC.LT.1 .OR. NLI.LT.1 .OR. NLD.LT.7) IERR = 1
    IF (NLDPRM(5).EQ.0D0) IERR = 1
    IF (NLDPRM(6).EQ.0D0) IERR = 1
    IF (NLDPRM(7).EQ.0D0) IERR = 1

    CONTRL = 0

  ELSE IF (OPCODE.EQ.-1) THEN
    WORLD(1) = NLDPRM(3) + NLDPRM(5)*(PIXEL(1) - NLDPRM(1))
    WORLD(2) = NLDPRM(4) + NLDPRM(6)*(PIXEL(2) - NLDPRM(2)) + PIXEL(1)*NLDPRM(7)

  ELSE
    IERR = 1
  END IF

  RETURN
END SUBROUTINE FSCAN

! Main program to test FSCAN
PROGRAM testFSCAN
  IMPLICIT NONE
  INTEGER :: OPCODE, NLC, NLI, NLD, CONTRL, IERR
  DOUBLE PRECISION :: CONTXT(20), PIXEL(2), WORLD(2), NLDPRM(7)
  CHARACTER :: NLCPRM(1)*1
  INTEGER :: NLIPRM(1)

  ! Initialize variables for the test
  NLC = 0
  NLI = 1
  NLIPRM(1) = 0
  NLD = 7
  NLDPRM = (/1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0/)
  WORLD = (/10.0D0, 20.0D0/)
  CONTXT = 0.0D0
  CONTRL = 0

  ! Test with OPCODE > 0
  OPCODE = 1
  CALL FSCAN(OPCODE, NLC, NLI, NLD, NLCPRM, NLIPRM, NLDPRM, WORLD, PIXEL, CONTRL, CONTXT, IERR)
  PRINT *, 'Test with OPCODE > 0: PIXEL =', PIXEL, 'IERR =', IERR

  ! Add more tests as necessary

END PROGRAM testFSCAN