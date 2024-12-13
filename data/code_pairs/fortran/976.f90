module mymath
    implicit none
    contains
    function Lagrange(x, y, z, n) result(fn)
        real, intent(in) :: x(:), y(:), z
        integer, intent(in) :: n
        real :: fn
        integer :: i, j
        real :: prod

        fn = 0.0
        do i = 1, n
            prod = 1.0
            do j = 1, n    
                if (j == i) then
                    cycle
                end if
                prod = prod * ((z - x(j)) / (x(i) - x(j)))
            end do
            fn = fn + prod * y(i)
        end do
    end function Lagrange
end module mymath