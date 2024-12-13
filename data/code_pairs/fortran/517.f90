! combined_program_and_tests.f90
module huj_mod
contains
    pure function huj() result(res)
        integer :: res(3)
        res = (/1, 2, 3/)
    end function huj
end module huj_mod

program combined
    use huj_mod
    implicit none
    integer :: a(3)
    integer :: i
    logical :: test_passed

    a = huj()
    if (.not. all(a == (/1, 2, 3/))) call abort()

    a = hoj()
    if (.not. all(a == (/1, 2, 3/))) call abort()

    ! Test for huj() function
    a = huj()
    test_passed = .true.
    do i = 1, 3
        if (a(i) /= i) then
            test_passed = .false.
            exit
        endif
    end do
    if (test_passed) then
        print *, "huj() test passed."
    else
        print *, "huj() test failed."
    endif

    ! Test for hoj() function
    a = hoj()
    test_passed = .true.
    do i = 1, 3
        if (a(i) /= i) then
            test_passed = .false.
            exit
        endif
    end do
    if (test_passed) then
        print *, "hoj() test passed."
    else
        print *, "hoj() test failed."
    endif

contains
    pure function hoj() result(res)
        integer :: res(3)
        res = (/1, 2, 3/)
    end function hoj
end program combined