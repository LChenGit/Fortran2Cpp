PROGRAM testverbatim
    IMPLICIT NONE
#ifdef TEST
    CALL test_no_output()
#endif
END PROGRAM testverbatim

SUBROUTINE test_no_output()
    PRINT*, 'Running test_no_output: Expect no other output...'
END SUBROUTINE test_no_output