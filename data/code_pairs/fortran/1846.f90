! This defines a module containing the factorial function
module factorial_mod
    implicit none
contains
    ! Factorial function
    function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact, i

        fact = 1
        do i = 1, n
            fact = fact * i
        end do
    end function factorial
end module factorial_mod

! Test program for the factorial function
program test_factorial
    use factorial_mod
    implicit none
    integer :: input, output

    ! Test the factorial function with a known input
    input = 5
    output = factorial(input)
    if (output == 120) then
        print *, "Test passed! Factorial of", input, "is", output
    else
        print *, "Test failed!"
    end if
end program test_factorial