module factorial_mod
    implicit none
contains
    recursive function factorial(n) result(res)
        integer, intent(in) :: n
        integer :: res
        if (n < 1) then
            res = 1
        else
            res = n * factorial(n - 1)
        end if
    end function factorial
end module factorial_mod