program openacc_clause_validity

  implicit none

  integer :: N
  real(8) :: a(256)

  N = 256

  !$acc parallel loop
  do i = 1, N
    a(i) = 3.14
  end do
  !$acc end parallel loop

end program openacc_clause_validity