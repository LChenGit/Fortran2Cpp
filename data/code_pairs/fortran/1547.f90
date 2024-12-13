SUBROUTINE PWRZGT(KCHAR, JCHAR, INDEX, NSIZE, IPOINT)
  CHARACTER(LEN=1), INTENT(IN) :: KCHAR
  CHARACTER(LEN=1), DIMENSION(NSIZE), INTENT(IN) :: JCHAR
  INTEGER, DIMENSION(NSIZE), INTENT(IN) :: INDEX
  INTEGER, INTENT(IN) :: NSIZE
  INTEGER, INTENT(OUT) :: IPOINT

  INTEGER :: KOUNT, IBOT, ITOP, I

  KOUNT = 0
  IBOT = 1
  ITOP = NSIZE
  I = ITOP

  DO
      I = (IBOT + ITOP) / 2
      KOUNT = KOUNT + 1
      IF (KOUNT > 10) THEN
          IPOINT = -1
          RETURN
      END IF
      IF (JCHAR(I) > KCHAR) THEN
          ITOP = I - 1
      ELSEIF (JCHAR(I) < KCHAR) THEN
          IBOT = I + 1
      ELSE
          IPOINT = INDEX(I)
          RETURN
      END IF
      IF (IBOT > ITOP) THEN
          IPOINT = -1
          RETURN
      END IF
  END DO
END SUBROUTINE PWRZGT

PROGRAM TestPWRZGT
  IMPLICIT NONE
  CHARACTER(LEN=1), DIMENSION(5) :: JCHAR = ['A', 'B', 'C', 'D', 'E']
  INTEGER, DIMENSION(5) :: INDEX = [1, 2, 3, 4, 5]
  INTEGER :: IPOINT, NSIZE
  CHARACTER(LEN=1) :: KCHAR

  NSIZE = 5

  ! Test 1: Search for a character in the middle
  KCHAR = 'C'
  CALL PWRZGT(KCHAR, JCHAR, INDEX, NSIZE, IPOINT)
  IF (IPOINT == 3) THEN
    PRINT *, "Test 1 Passed"
  ELSE
    PRINT *, "Test 1 Failed"
  END IF

  ! Test 2: Search for a character not in the array
  KCHAR = 'Z'
  CALL PWRZGT(KCHAR, JCHAR, INDEX, NSIZE, IPOINT)
  IF (IPOINT == -1) THEN
    PRINT *, "Test 2 Passed"
  ELSE
    PRINT *, "Test 2 Failed"
  END IF
END PROGRAM TestPWRZGT