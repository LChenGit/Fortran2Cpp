module nt_FunctionsModule
    implicit none
    public :: nt_logistic, logisticd, const, constd

contains

    function nt_logistic(x, args) result(fx)
        real, intent(in) :: x
        real, intent(in) :: args(:)
        real :: fx

        fx = args(1) / (args(2) + exp(-args(3) * x))
    end function nt_logistic

    function logisticd(args, x) result(fx)
        real, intent(in) :: args(:)
        real, intent(in) :: x
        real :: fx

        fx = 2.0 / (1.0 + exp(-2.0*x)) - 1.0
    end function logisticd

    function const(args, x) result(fx)
        real, intent(in) :: args(:)
        real, intent(in) :: x
        real :: fx

        fx = args(1)
    end function const

    function constd(args, x) result(fx)
        real, intent(in) :: args(:)
        real, intent(in) :: x
        real :: fx

        fx = args(1) / 2.0
    end function constd

end module nt_FunctionsModule