module print_tools
    implicit none
    integer, parameter :: stdout = 6
contains
    subroutine print_rmatrix(name, m)
        character(*), intent(in) :: name
        real, dimension(:, :), intent(in) :: m
        integer :: num_rows, num_cols, r, c
        num_rows = size(m, 1)
        num_cols = size(m, 2)
        write(unit=stdout, fmt='(A)') name // ':'
        do r = 1, num_rows
            write(unit=stdout, fmt='(20F10.3)') (m(r, c), c=1,num_cols)
        end do
    end subroutine print_rmatrix
end module print_tools

module m
    use print_tools
    implicit none
contains
    pure function f(i, j)
        integer, intent(in) :: i, j
        real :: f
        f = 1.0 * i * j
    end function f

    subroutine call_test(nrows, ncols)
        integer, intent(in) :: nrows, ncols
        real :: array6(1:nrows, 1:ncols)
        real :: array7(1:nrows, 1:ncols)
        integer :: r, c

        do r = 1, nrows
            do c = 1, ncols
                array6(r, c) = 1.0 * r * c
            end do
        end do
        call print_rmatrix("array6", array6)

        do r = 1, nrows
            do c = 1, ncols
                array7(r, c) = f(r, c) * 2.0
            end do
        end do
        call print_rmatrix("array7", array7)

        do r = 1, nrows
            do c = 1, ncols
                array7(r, c) = array6(r, c) * 2.0
            end do
        end do
        call print_rmatrix("array7", array7)
    end subroutine call_test
end module m

program claw_test
    use m
    call call_test(10, 20)
end program claw_test