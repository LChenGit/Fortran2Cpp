module matrix_mod
  implicit none

  type :: Matrix
     integer :: rows
     integer :: columns
     real, allocatable :: data(:,:)
  end type Matrix

contains

  subroutine initialize_matrix(this, rows, columns)
    class(Matrix), intent(inout) :: this
    integer, intent(in) :: rows, columns

    this%rows = rows
    this%columns = columns
    allocate(this%data(rows, columns))
  end subroutine initialize_matrix

end module matrix_mod