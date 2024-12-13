module comb_tmplalm_mod
    implicit none

    ! Assuming these are defined for the example
    integer, parameter :: s2_sp = kind(1.0)
    integer, parameter :: s2_spc = kind((1.0,1.0))

    public :: comb_tmplalm_gaussian

contains

    function comb_tmplalm_gaussian(el, m, param) result(val)
        integer, intent(in) :: el, m
        real(s2_sp), intent(in), optional :: param(:)
        complex(s2_spc) :: val

        real(s2_sp) :: sigma = 0.05e0

        if (present(param)) then
            if (size(param) /= 1) then
                call comb_error('comb_tmplalm_gaussian')
            endif
            sigma = param(1)
        endif

        if (m == 0) then
            val = exp(-el*el*sigma*sigma/2e0)
        else
            val = (0.0, 0.0)
        endif
    end function comb_tmplalm_gaussian

    subroutine comb_error(function_name)
        character(len=*), intent(in) :: function_name
        write(*,*) "Error in", trim(function_name), ": Invalid parameter size."
        stop
    end subroutine comb_error

end module comb_tmplalm_mod