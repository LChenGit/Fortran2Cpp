MODULE globals
  TYPE, BIND(C) :: type1
     INTEGER :: x
  END TYPE type1
  TYPE(type1) :: pdm_bps
END MODULE globals

PROGRAM main
  USE globals
  pdm_bps%x = 10
  CALL print_values
END PROGRAM main

SUBROUTINE print_values
  USE globals
  PRINT *, "pdm_bps%x = ", pdm_bps%x
END SUBROUTINE print_values