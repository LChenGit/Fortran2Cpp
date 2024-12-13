! data_diag.f90
module data_diag
  implicit none
  public
  logical               :: dump_mesh_info_files = .false.
  logical               :: dump_mesh_info_screen = .false.
  logical               :: dump_mesh_vtk = .false.
  logical               :: dump_1dmodel = .false.
  logical               :: only_suggest_ntheta = .false.
  character(len=200)    :: diagpath = " "
  integer               :: lfdiag = 0
end module data_diag