! ppm_module_mesh_block_intersect.f90
MODULE ppm_module_mesh_block_intersect

CONTAINS

  SUBROUTINE ppm_mesh_block_intersect(result)
    INTEGER, INTENT(OUT) :: result
    result = 42
  END SUBROUTINE ppm_mesh_block_intersect

END MODULE ppm_module_mesh_block_intersect

! main.f90
PROGRAM main
  USE ppm_module_mesh_block_intersect
  IMPLICIT NONE

  INTEGER :: result
  INTEGER :: expected_value = 42

  CALL ppm_mesh_block_intersect(result)

  IF (result == expected_value) THEN
      PRINT *, 'Test passed!'
  ELSE
      PRINT *, 'Test failed. Expected:', expected_value, 'Got:', result
  END IF

END PROGRAM main