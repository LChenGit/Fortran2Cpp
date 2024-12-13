! program.f90
SUBROUTINE test(str)
  CHARACTER(len=*), INTENT(IN) :: str
  PRINT *, 'Testing with string:', TRIM(str)
END SUBROUTINE test

PROGRAM main
  CALL test('abc')
END PROGRAM main