module math_operations
    implicit none
contains
    function add(a, b)
        integer, intent(in) :: a, b
        integer :: add

        add = a + b
    end function add
end module math_operations