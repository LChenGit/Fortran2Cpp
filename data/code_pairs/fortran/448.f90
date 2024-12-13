module maxval_subroutines
    implicit none
contains

    subroutine maxval_i_js2(array, maxValue)
        integer, dimension(:), intent(in) :: array
        integer, intent(out) :: maxValue
        maxValue = maxval(array)
    end subroutine maxval_i_js2

    subroutine maxval_i_ss2(array, maxValue)
        integer, dimension(:), intent(in) :: array
        integer, intent(out) :: maxValue
        maxValue = maxval(array)
    end subroutine maxval_i_ss2

end module maxval_subroutines