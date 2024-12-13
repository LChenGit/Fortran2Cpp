module ppm_module_tree_cutpos
    implicit none
contains
    subroutine ppm_tree_cutpos_s(result)
        real(kind=4), intent(out) :: result
        result = 1.23
    end subroutine ppm_tree_cutpos_s

    subroutine ppm_tree_cutpos_d(result)
        real(kind=8), intent(out) :: result
        result = 1.2345678901234567
    end subroutine ppm_tree_cutpos_d
end module ppm_module_tree_cutpos