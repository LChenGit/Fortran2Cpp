MODULE ppm_module_topo_box2subs

CONTAINS

  SUBROUTINE ppm_topo_box2subs_s(a, b, result)
    REAL, INTENT(IN) :: a, b
    REAL, INTENT(OUT) :: result
    result = a * b  ! Example operation for single precision
  END SUBROUTINE ppm_topo_box2subs_s

  SUBROUTINE ppm_topo_box2subs_d(a, b, result)
    DOUBLE PRECISION, INTENT(IN) :: a, b
    DOUBLE PRECISION, INTENT(OUT) :: result
    result = a * b  ! Example operation for double precision
  END SUBROUTINE ppm_topo_box2subs_d

END MODULE ppm_module_topo_box2subs