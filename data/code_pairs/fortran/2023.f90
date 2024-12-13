module math_operations
    implicit none
contains
    function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact
        integer :: i
        fact = 1
        do i = 2, n
            fact = fact * i
        end do
    end function factorial
end module math_operations