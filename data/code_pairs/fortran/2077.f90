program factorial_test
    implicit none

    call test_fact()

contains

    function fact(n) result(f)
        integer, intent(in) :: n
        integer :: f

        if (n <= 1) then
            f = 1
        else
            f = n * fact(n - 1)
        endif
    end function fact

    subroutine test_fact()
        integer :: expected, computed

        ! Test case 1: Fact(5)
        expected = 120
        computed = fact(5)
        call assert_equals(computed, expected, "Fact(5)")

        ! Test case 2: Fact(0)
        expected = 1
        computed = fact(0)
        call assert_equals(computed, expected, "Fact(0)")

        ! Add more test cases as needed
    end subroutine test_fact

    subroutine assert_equals(computed, expected, test_label)
        integer, intent(in) :: computed, expected
        character(len=*), intent(in) :: test_label

        if (computed == expected) then
            print *, "PASS: ", test_label
        else
            print *, "FAIL: ", test_label, " Expected: ", expected, ", Got: ", computed
        endif
    end subroutine assert_equals

end program factorial_test