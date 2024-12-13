module futility_mod
    implicit none
contains
    subroutine print_array(arr)
        real, dimension(:), intent(in) :: arr
        integer :: i
        do i = 1, size(arr)
            print *, "Element", i, ":", arr(i)
        end do
    end subroutine print_array
end module futility_mod

program futility_demo
    use futility_mod
    implicit none
    real :: arr(3) = [1.0, 2.0, 3.0]
    real :: dot_product_result
    real :: root
    real :: derivative_result
    real, parameter :: pi = 3.141592653589793

    call print_array(arr)
    dot_product_result = sum(arr*arr)
    print *, "Dot product of arr with itself:", dot_product_result

    root = -1.0  ! Placeholder for root finding demonstration
    print *, "Root found (placeholder):", root

    derivative_result = 0.0  ! Placeholder for calculus demonstration
    print *, "Derivative result (placeholder):", derivative_result

    print *, "Value of PI:", pi
end program futility_demo