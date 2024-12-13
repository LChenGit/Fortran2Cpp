! math_operations.f90
module math_operations
    implicit none
contains
    function add(a, b) result(c)
        integer, intent(in) :: a, b
        integer :: c
        c = a + b
    end function add
end module math_operations