! subroutines.f90
SUBROUTINE SETUP
    PRINT *, 'SETUP called'
END SUBROUTINE SETUP

SUBROUTINE CLEAR
    PRINT *, 'CLEAR called'
END SUBROUTINE CLEAR

SUBROUTINE GMODE
    PRINT *, 'GMODE called'
END SUBROUTINE GMODE

SUBROUTINE TMODE
    PRINT *, 'TMODE called'
END SUBROUTINE TMODE

! Assuming the test program is in a separate file for clarity
PROGRAM test_subroutines
    CALL SETUP()
    PRINT *, 'SETUP test passed.'
    CALL CLEAR()
    PRINT *, 'CLEAR test passed.'
    CALL GMODE()
    PRINT *, 'GMODE test passed.'
    CALL TMODE()
    PRINT *, 'TMODE test passed.'
    PRINT *, 'All tests completed.'
END PROGRAM test_subroutines