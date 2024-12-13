! Module for matrix operations
module matrix_operations
  implicit none
contains
  ! Subroutine to initialize a matrix to zero
  subroutine matrix_initialize_to_zero(c, n)
    integer, intent(in) :: n
    real(8), dimension(n,n), intent(out) :: c
    c = 0.d0
  end subroutine matrix_initialize_to_zero
end module matrix_operations

! Program to test the initialization of a matrix to zero
program test_matrix_initialization
  use matrix_operations
  implicit none
  integer :: n
  real(8), allocatable :: c(:,:)

  ! Specify the size of the matrix
  n = 3

  ! Allocate the matrix
  allocate(c(n,n))

  ! Call the subroutine to initialize matrix c to zero
  call matrix_initialize_to_zero(c, n)

  ! Check if matrix c is correctly initialized to zero
  if (all(c == 0.d0)) then
    print *, "Fortran Test Passed: Matrix c is correctly initialized to zero."
  else
    print *, "Fortran Test Failed: Matrix c is not correctly initialized."
  end if

  ! Deallocate the matrix
  deallocate(c)
end program test_matrix_initialization