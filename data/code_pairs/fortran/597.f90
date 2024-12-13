program factorialTest
    implicit none
    call testFactorial()
contains

    function factorial(n) result(res)
        integer, intent(in) :: n
        integer :: res
        integer :: i
        
        if (n == 0) then
            res = 1
            return
        end if

        res = 1
        do i = 1, n
            res = res * i
        end do
    end function factorial

    subroutine testFactorial()
        integer :: expected, computed

        ! Test 1
        expected = 120  ! 5!
        computed = factorial(5)
        call assertEqual(computed, expected, "Test 1")

        ! Test 2
        expected = 1  ! 0!
        computed = factorial(0)
        call assertEqual(computed, expected, "Test 2")

        ! Add more tests as needed
    end subroutine testFactorial

    subroutine assertEqual(computed, expected, message)
        integer, intent(in) :: computed, expected
        character(len=*), intent(in) :: message
        
        if (computed .eq. expected) then
            print *, message, ": Success"
        else
            print *, message, ": Failure. Expected", expected, "but got", computed
        end if
    end subroutine assertEqual

end program factorialTest