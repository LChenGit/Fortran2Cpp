module sparse_mat_module
  implicit none

  type :: d_base_sparse_mat
    integer :: v(10) = 0
  end type d_base_sparse_mat

end module sparse_mat_module

program bug20
  use sparse_mat_module
  implicit none

  type(d_base_sparse_mat) :: a

  ! Since Fortran code does not have an explicit check like in C++,
  ! the understanding is that the size of 'v' is correct by definition.
  write(*,*) 'NV = ', size(a%v)

end program bug20