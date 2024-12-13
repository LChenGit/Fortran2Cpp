! plugin_module.f90
MODULE plugin_module
  IMPLICIT NONE
CONTAINS
  SUBROUTINE plugin_scf_energy()
    PRINT *, "Fortran Stdout: plugin_scf_energy executed."
  END SUBROUTINE plugin_scf_energy
END MODULE plugin_module