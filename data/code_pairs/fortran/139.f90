module c_arrays
    implicit none
contains

    function array_in(x, n) result(sum)
        real, intent(in) :: x(:)
        integer, intent(in) :: n
        real :: sum
        integer :: i
        
        sum = 0.0
        do i = 1, n
            sum = sum + x(i)
        end do
    end function array_in

    function array_in_2(x) result(sum)
        real, intent(in) :: x(:)
        real :: sum
        integer :: i, upb
        
        upb = min(size(x), 4) ! Upper bound is the smaller of 4 or the array size
        sum = 0.0
        do i = 1, upb
            sum = sum + x(i)
        end do
    end function array_in_2

    subroutine array_out(x, y, nx, ny)
        integer, intent(in) :: nx, ny
        real, intent(out) :: x(nx), y(ny)
        
        x = 20.0
        y = 30.0
    end subroutine array_out

    function inner_prod(a, b, n) result(dot_product)
        real, intent(in) :: a(:), b(:)
        integer, intent(in) :: n
        real :: dot_product
        integer :: i
        
        dot_product = 0.0
        do i = 1, n
            dot_product = dot_product + a(i) * b(i)
        end do
    end function inner_prod

end module c_arrays