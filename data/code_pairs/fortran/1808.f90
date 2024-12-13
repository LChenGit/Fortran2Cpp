MODULE types
  IMPLICIT NONE
  PUBLIC :: t_comm_variable, bbstr, grid_comm_pattern_type, send_type

  TYPE :: t_comm_variable
    TYPE(grid_comm_pattern_type), ALLOCATABLE :: grid_comm_pattern
  END TYPE t_comm_variable

  TYPE :: grid_comm_pattern_type
    TYPE(send_type), ALLOCATABLE :: send(:)
  END TYPE grid_comm_pattern_type

  TYPE :: send_type
    INTEGER, ALLOCATABLE :: index_no(:)
  END TYPE send_type

  TYPE :: bbstr
    ! Assuming some components for illustration
    INTEGER :: dummy
  END TYPE bbstr

END MODULE types