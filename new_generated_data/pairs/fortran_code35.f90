! File: identity_function.f90

! Interface for subroutines/functions being tested
Abstract Interface
    Function IdentityInterface(x) Result(y)
        Integer, Intent(In) :: x
        Integer :: y
    End Function IdentityInterface
End Interface

Contains

    ! Implementation of the identity function
    Function IdentityFunc(x) Result(res)
        Integer, Intent(in) :: x
        Integer :: res
        res = x
    End Function IdentityFunc

! Main program to test the identity function
Program Main
    Use, Intrinsic :: iso_fortran_env, only : stdout => output_unit, stdin => input_unit, stderr => error_unit
    Implicit None

    ! Local variables for testing
    Integer :: test_value
    Class(IdentityInterface) :: identity_instance

    ! Test cases
    test_value = 5
    identity_instance = IdentityFunc
    If (identity_instance(test_value) /= test_value) Then
        Write (stderr, *) "Test: Identity function failed for positive integer."
        Stop 1
    End If

    test_value = -3
    If (identity_instance(test_value) /= test_value) Then
        Write (stderr, *) "Test: Identity function failed for negative integer."
        Stop 1
    End If

    test_value = 0
    If (identity_instance(test_value) /= test_value) Then
        Write (stderr, *) "Test: Identity function failed for zero."
        Stop 1
    End If

    Write (stdout, *) "All tests for identity function passed."

End Program Main