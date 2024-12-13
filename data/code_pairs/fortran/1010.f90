MODULE ppm_module_mesh_derive
    IMPLICIT NONE
CONTAINS
    SUBROUTINE ppm_mesh_derive()
        PRINT *, "ppm_mesh_derive called"
    END SUBROUTINE ppm_mesh_derive
END MODULE ppm_module_mesh_derive

PROGRAM test_ppm_mesh_derive
    USE ppm_module_mesh_derive
    IMPLICIT NONE
    CALL ppm_mesh_derive()
END PROGRAM test_ppm_mesh_derive