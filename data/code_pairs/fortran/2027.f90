! This code snippet should ideally be placed in a module or similar structure
! However, for the purpose of simplicity, variables are defined in the main program or a subroutine

INTEGER :: ct_lun = 0
INTEGER :: ion_lun = 0
INTEGER :: curr_lsf_num = 0
CHARACTER(len=1) :: sf_name = ' '
CHARACTER(len=1) :: def_map = ' '
LOGICAL :: cal_init = .FALSE.
LOGICAL :: ion_init = .FALSE.
LOGICAL :: map_init = .FALSE.
LOGICAL :: rem_init = .FALSE.