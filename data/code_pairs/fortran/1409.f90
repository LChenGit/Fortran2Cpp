module m_dynamic_init_variables
    implicit none
    integer, parameter :: kbcInitial = 1, kint = 4

contains

    subroutine dynamic_init_variables(hecMESH, hecMAT, fstrSOLID, fstrEIG, fstrDYNAMIC, fstrPARAM)
        implicit none
        type(hecmwST_local_mesh), intent(in) :: hecMESH
        type(hecmwST_matrix), intent(in) :: hecMAT
        type(fstr_solid), intent(in) :: fstrSOLID
        type(fstr_eigen), intent(in) :: fstrEIG
        type(fstr_dynamic), intent(inout) :: fstrDYNAMIC
        type(fstr_param), intent(in) :: fstrPARAM
        integer :: j

        ! Assuming dynamic_mat_ass_load is adequately defined elsewhere.
        ! call dynamic_mat_ass_load(hecMESH, hecMAT, fstrSOLID, fstrDYNAMIC, fstrPARAM)

        if (fstrSOLID%VELOCITY_type == kbcInitial) then
            do j = 1, hecMESH%n_node * hecMESH%n_dof
                fstrDYNAMIC%ACC(j, 1) = (hecMAT%B(j) - fstrDYNAMIC%ray_m * fstrEIG%mass(j) * fstrDYNAMIC%VEL(j, 1)) / fstrEIG%mass(j)
            end do
        elseif (fstrSOLID%ACCELERATION_type == kbcInitial) then
            do j = 1, hecMESH%n_node * hecMESH%n_dof
                fstrDYNAMIC%VEL(j, 1) = (hecMAT%B(j) - fstrEIG%mass(j) * fstrDYNAMIC%ACC(j, 1)) / (fstrDYNAMIC%ray_m * fstrEIG%mass(j))
            end do
        endif
    end subroutine dynamic_init_variables

end module m_dynamic_init_variables