PROGRAM test_program
  CALL test_dummy_subroutine
END PROGRAM

SUBROUTINE dummy_subroutine
  INTEGER :: i
  DO i=1,10
    PRINT *, 'First loop body:',i
  END DO

  DO i=1,10
    PRINT *, 'Second loop body:',i
  END DO
END SUBROUTINE

SUBROUTINE test_dummy_subroutine
  INTEGER :: i, count
  count = 0

  DO i=1,10
    count = count + 1
  END DO

  IF (count == 10) THEN
    PRINT *, "First loop test passed."
  ELSE
    PRINT *, "First loop test failed."
  END IF

  count = 0
  DO i=1,10
    count = count + 1
  END DO

  IF (count == 10) THEN
    PRINT *, "Second loop test passed."
  ELSE
    PRINT *, "Second loop test failed."
  END IF
END SUBROUTINE