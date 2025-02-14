module NumericalModule
        contains
            subroutine NumericalSubroutine(a)
                real, intent(inout) :: a(:)
                integer :: j
                
                do j = 1, size(a)
                    a(j) = 5.0 - 0.1 * j
                end do
            end subroutine NumericalSubroutine
    end module NumericalModule

    program MainProgram
        use NumericalModule
        
        implicit none
        
        integer, parameter :: n = 10
        real, dimension(n) :: a_actual
        real, dimension(n) :: a_expected
        real :: tolerance = 0.0001
        integer :: i
        
        ! Initialize actual array with ones
        a_actual = 1.0
        
        ! Compute expected values
        do i = 1, n
            a_expected(i) = 5.0 - 0.1 * i
        end do
        
        call NumericalSubroutine(a_actual)
        
        print *, "Fortran Output:"
        print *, "Index | Actual | Expected | Pass"
        
        all_pass = .true.
        do i = 1, n
            if (abs(a_actual(i) - a_expected(i)) > tolerance) then
                all_pass = .false.
            end if
            print *, i, "|", a_actual(i), "|", a_expected(i), &
                     "|", "Pass"
        end do
        
        print *, ""
        print *, "Test Passed: ", all_pass
    end program MainProgram