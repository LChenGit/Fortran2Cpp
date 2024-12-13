module m_boundary_params_sph_MHD
  implicit none

  ! Type definition for demonstration purposes
  type sph_boundary_type
    integer :: dummy  ! Placeholder
  end type sph_boundary_type

  type(sph_boundary_type) :: sph_bc_U
  type(sph_boundary_type) :: sph_bc_B
  type(sph_boundary_type) :: sph_bc_T
  type(sph_boundary_type) :: sph_bc_C

  real, allocatable :: vp_ICB_bc(:)
  real, allocatable :: vt_ICB_bc(:)
  real, allocatable :: vp_CMB_bc(:)
  real, allocatable :: vt_CMB_bc(:)

contains

  subroutine allocate_vsp_bc_array(jmax)
    integer, intent(in) :: jmax

    allocate(vp_ICB_bc(jmax))
    allocate(vt_ICB_bc(jmax))
    allocate(vp_CMB_bc(jmax))
    allocate(vt_CMB_bc(jmax))
    vp_ICB_bc = 0.0
    vt_ICB_bc = 0.0
    vp_CMB_bc = 0.0
    vt_CMB_bc = 0.0
  end subroutine allocate_vsp_bc_array

  subroutine deallocate_vsp_bc_array
    deallocate(vp_ICB_bc, vt_ICB_bc)
    deallocate(vp_CMB_bc, vt_CMB_bc)
  end subroutine deallocate_vsp_bc_array

end module m_boundary_params_sph_MHD