PROGRAM TestLSAME
  IMPLICIT NONE
  LOGICAL :: LSAME
  CHARACTER*1 :: CA, CB

  ! Test 1: Identical lowercase characters
  CA = 'a'
  CB = 'a'
  PRINT *, 'Test 1 (a, a): ', LSAME(CA, CB)  ! Expected: TRUE

  ! Test 2: Identical uppercase characters
  CA = 'A'
  CB = 'A'
  PRINT *, 'Test 2 (A, A): ', LSAME(CA, CB)  ! Expected: TRUE

  ! Test 3: Different characters
  CA = 'a'
  CB = 'b'
  PRINT *, 'Test 3 (a, b): ', LSAME(CA, CB)  ! Expected: FALSE

  ! Test 4: Same letter, different case
  CA = 'a'
  CB = 'A'
  PRINT *, 'Test 4 (a, A): ', LSAME(CA, CB)  ! Expected: TRUE

END PROGRAM TestLSAME

LOGICAL FUNCTION LSAME (CA, CB)
  CHARACTER(LEN=1) :: CA, CB
  INTEGER :: IOFF
  LOGICAL, SAVE :: FIRST = .TRUE.
  IF (FIRST) THEN
      IOFF = ICHAR('a') - ICHAR('A')
      FIRST = .FALSE.
  END IF
  LSAME = (CA == CB) .OR. (ICHAR(CA) == ICHAR(CB) + IOFF) .OR. &
          (ICHAR(CA) + IOFF == ICHAR(CB))
END FUNCTION LSAME