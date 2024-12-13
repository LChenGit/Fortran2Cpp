module ppm_module_hamjac_ext
contains
    subroutine ppm_hamjac_ext_step_3ds
        print *, "This is the single precision routine in Fortran."
    end subroutine ppm_hamjac_ext_step_3ds

    subroutine ppm_hamjac_ext_step_3dd
        print *, "This is the double precision routine in Fortran."
    end subroutine ppm_hamjac_ext_step_3dd
end module ppm_module_hamjac_ext