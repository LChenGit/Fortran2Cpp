PROGRAM Main
  CALL subr1(3.0, 4.0)
  CALL subr2
END PROGRAM Main

INTEGER FUNCTION ifun(arg1, arg2)
  INTEGER, INTENT(IN) :: arg1, arg2
  ifun = arg1 + arg2
END FUNCTION ifun

DOUBLE PRECISION FUNCTION jfun(arg1)
  DOUBLE PRECISION, INTENT(IN) :: arg1
  jfun = SQRT(arg1)
END FUNCTION jfun

SUBROUTINE subr1(a, b)
  DOUBLE PRECISION, INTENT(IN) :: a, b
  DOUBLE PRECISION :: c
  DOUBLE PRECISION :: arrayA(3,4,3)
  c = MAX(a, b)
  arrayA(1,1,1) = c
  PRINT *, 'Value is ', c
END SUBROUTINE subr1

SUBROUTINE subr2
  DOUBLE PRECISION :: i, l
  INTEGER :: j, m
  PRINT *, 'inside subroutine subr2'
  i = 1.0
  j = 2
  m = 3
  l = 4.5
  PRINT *, 'IFUN RETURNS ', ifun(j, m)
  PRINT *, 'JFUN RETURNS ', jfun(i + l)
END SUBROUTINE subr2