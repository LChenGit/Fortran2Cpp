! hello.f90
program hello
    call greet
    call performCalculation
end program hello

subroutine greet
    print *, "Hello, World!"
end subroutine greet

subroutine performCalculation
    ! This subroutine calculates the sum of 3 and 4 and prints the result.
    integer :: result
    result = 3 + 4
    print *, "The sum of 3 and 4 is", result, "."
end subroutine performCalculation