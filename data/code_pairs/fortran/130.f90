module where_logic
    implicit none
contains
    subroutine modify_arrays(a, b)
        integer, intent(in) :: a(:)
        integer, intent(inout) :: b(:)
        where (a == 1)
            b = 0    ! This line makes it explicit, even though it's already the initialized value.
        elsewhere
            b = 2
        end where
    end subroutine modify_arrays
end module where_logic

program test_program
    use where_logic
    implicit none
    integer :: a(5) = (/1, 2, 3, 4, 5/)
    integer :: b(5) = (/0, 0, 0, 0, 0/)
    integer :: expected_b(5) = (/0, 2, 2, 2, 2/)
    logical :: test_passed

    call modify_arrays(a, b)

    test_passed = all(b == expected_b)
    if (.not. test_passed) then
        print *, 'Test failed: Arrays do not match.'
        stop 1
    else
        print *, 'Test passed.'
    endif
end program test_program