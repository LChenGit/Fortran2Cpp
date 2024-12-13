module h_global_vars
    ! This module could contain global variables or parameters if needed
end module h_global_vars

module x_dot_mod
    use h_global_vars
    implicit none
contains
    function x_dot(kon_1, koff_1, kon_2, koff_2, f_plus, g_minus, g_plus, Ca, x) result(f)
        real, intent(in) :: kon_1, koff_1, kon_2, koff_2, f_plus, g_minus, g_plus, Ca
        real, dimension(4), intent(in) :: x
        real, dimension(4) :: f

        f(1) = -kon_1 * Ca * x(1) + koff_1 * x(2) + g_minus * x(4)
        f(2) =  kon_1 * Ca * x(1) - (koff_1 + f_plus) * x(2) + g_plus * x(3)
        f(3) =  f_plus * x(2) - (g_plus + koff_2) * x(3) + kon_2 * Ca * x(4)
        f(4) =  koff_2 * x(3) - (g_minus + kon_2 * Ca) * x(4)
    end function x_dot
end module x_dot_mod