module factorial_module
contains
    recursive function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact
        if (n <= 1) then
            fact = 1
        else
            fact = n * factorial(n-1)
        endif
    end function factorial
end module factorial_module