! Define a module for flags if needed
MODULE plugin_flags
  ! Any necessary declarations go here
END MODULE plugin_flags

! Subroutine definition
SUBROUTINE plugin_clean(prog, lflag)
  USE plugin_flags
  IMPLICIT NONE
  CHARACTER(LEN=*), INTENT(IN) :: prog
  LOGICAL, INTENT(IN) :: lflag
  PRINT *, 'Program:', TRIM(prog)  ! Use TRIM to remove trailing spaces if necessary
  PRINT *, 'Flag:', lflag
END SUBROUTINE plugin_clean

! Main program for testing
PROGRAM test_plugin_clean
  USE plugin_flags
  IMPLICIT NONE
  CALL plugin_clean('TestProgram', .TRUE.)
  CALL plugin_clean('AnotherTest', .FALSE.)
END PROGRAM test_plugin_clean