module quadratic_parameters
    double precision :: a, b, c
contains
    subroutine quadratic_set(new_a, new_b, new_c)
        implicit none
        double precision, intent(in) :: new_a, new_b, new_c
        
        a = new_a
        b = new_b
        c = new_c
    end subroutine quadratic_set

    function quadratic(x) result(quadratic_result)
        implicit none
        double precision, intent(in) :: x
        double precision :: quadratic_result
        
        quadratic_result = a*x**2 + b*x + c
    end function quadratic
end module quadratic_parameters