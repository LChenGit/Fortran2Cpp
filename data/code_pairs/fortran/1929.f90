MODULE kinds
  IMPLICIT NONE
  INTEGER, PARAMETER :: DP = KIND(1.0D0)
END MODULE kinds

MODULE ions_base
  USE kinds, ONLY: DP
  IMPLICIT NONE
  REAL(KIND=DP), ALLOCATABLE :: if_pos(:,:)
END MODULE ions_base

MODULE path_variables
  USE kinds, ONLY: DP
  IMPLICIT NONE
  REAL(KIND=DP), ALLOCATABLE :: fix_atom_pos(:,:)
END MODULE path_variables

MODULE path_input_parameters_module
  IMPLICIT NONE
  INTEGER :: nat
END MODULE path_input_parameters_module

PROGRAM Main
  USE kinds
  USE ions_base
  USE path_variables
  USE path_input_parameters_module
  IMPLICIT NONE

  ! Initialize `nat` for demonstration purposes.
  nat = 3
  ALLOCATE(if_pos(3, nat))
  if_pos = RESHAPE(SOURCE=[1.0_DP, 2.0_DP, 3.0_DP, &
                           4.0_DP, 5.0_DP, 6.0_DP, &
                           7.0_DP, 8.0_DP, 9.0_DP], SHAPE=[3, nat])
  CALL engine_to_path_fix_atom_pos()

  ! Example: Output the result to verify correctness
  PRINT *, "Resulting fix_atom_pos:"
  PRINT *, fix_atom_pos

  DEALLOCATE(if_pos)
  DEALLOCATE(fix_atom_pos)
END PROGRAM Main

SUBROUTINE engine_to_path_fix_atom_pos()
  USE kinds, ONLY: DP
  USE ions_base, ONLY: if_pos
  USE path_variables, ONLY: fix_atom_pos
  USE path_input_parameters_module, ONLY: nat
  IMPLICIT NONE
  
  ALLOCATE(fix_atom_pos(3, nat))
  fix_atom_pos = if_pos
END SUBROUTINE engine_to_path_fix_atom_pos