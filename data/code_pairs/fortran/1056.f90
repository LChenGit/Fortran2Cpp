! Fortran program demonstrating equivalent functionality to the C++ example
program FortranEquivalent
    implicit none

! This is a simplified example to match the C++ unit test behavior

end program FortranEquivalent

! Assuming procedures would be here to match the tests
subroutine foo(a)
    integer, intent(inout) :: a(:)
    integer :: i
    do i = 1, size(a)
        a(i) = a(i) + 1
    end do
end subroutine foo

subroutine bar(c)
    character(len=*), intent(inout) :: c(:)
    integer :: i
    do i = 1, size(c)
        c(i) = 'Modified'
    end do
end subroutine bar