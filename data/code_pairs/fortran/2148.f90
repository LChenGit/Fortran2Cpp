MODULE ppm_module_color_edge
  IMPLICIT NONE

  TYPE :: vertex
      INTEGER :: degree
      INTEGER :: color
      INTEGER :: dsat
      LOGICAL :: iscolored
      INTEGER :: loc_heap
      INTEGER, ALLOCATABLE :: list(:)
  END TYPE vertex

  TYPE :: list
      INTEGER, ALLOCATABLE :: adj_edge(:)
  END TYPE list

  TYPE(vertex), ALLOCATABLE :: node(:)
  INTEGER, ALLOCATABLE :: nelem(:), offset(:)
  TYPE(list), ALLOCATABLE :: edges_per_node(:), lists(:)
  INTEGER, ALLOCATABLE :: node_sat(:,:)
  INTEGER, ALLOCATABLE :: size_heap(:)
  LOGICAL, ALLOCATABLE :: used_color(:)

  INTEGER :: nvertices = 0, nedges = 0, max_degree = 0, ncolor = 0, alloc_error = 0

CONTAINS

  SUBROUTINE ppm_color_edge()
    PRINT *, "ppm_color_edge called - implement your logic here."
  END SUBROUTINE ppm_color_edge

END MODULE ppm_module_color_edge