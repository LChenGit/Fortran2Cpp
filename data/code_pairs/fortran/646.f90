module ppm_module_fmm_traverse

contains

subroutine ppm_fmm_traverse_s_sf(result)
    integer, intent(out) :: result
    result = 1
end subroutine ppm_fmm_traverse_s_sf

subroutine ppm_fmm_traverse_d_sf(result)
    integer, intent(out) :: result
    result = 2
end subroutine ppm_fmm_traverse_d_sf

subroutine ppm_fmm_traverse_s_vf(result)
    integer, intent(out) :: result
    result = 3
end subroutine ppm_fmm_traverse_s_vf

subroutine ppm_fmm_traverse_d_vf(result)
    integer, intent(out) :: result
    result = 4
end subroutine ppm_fmm_traverse_d_vf

end module ppm_module_fmm_traverse