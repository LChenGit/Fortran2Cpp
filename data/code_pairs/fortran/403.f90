! ppm_module_tree_boxcut.f90
module ppm_module_tree_boxcut
    implicit none
contains
    ! Single precision function
    real(kind=4) function ppm_tree_boxcut_s(x)
        real(kind=4), intent(in) :: x
        ppm_tree_boxcut_s = x * x
    end function ppm_tree_boxcut_s

    ! Double precision function
    real(kind=8) function ppm_tree_boxcut_d(x)
        real(kind=8), intent(in) :: x
        ppm_tree_boxcut_d = x * x
    end function ppm_tree_boxcut_d
end module ppm_module_tree_boxcut