! This Fortran program demonstrates a simple module with a function and a 
! program that tests this function.

MODULE LmdVmixMod
IMPLICIT NONE
CONTAINS
    FUNCTION DoSomething(x) RESULT(y)
        REAL, INTENT(IN) :: x
        REAL :: y
        y = x * 2.0
    END FUNCTION DoSomething
END MODULE LmdVmixMod

PROGRAM TestLmdVmixMod
    USE LmdVmixMod
    IMPLICIT NONE
    REAL :: result

    result = DoSomething(5.0)
    PRINT *, "Result of DoSomething(5.0): ", result
END PROGRAM TestLmdVmixMod