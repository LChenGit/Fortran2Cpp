! Filename: foo.f90
module foo_module
contains
  subroutine foo (r)
    integer :: i, r
    !$omp parallel do reduction(+: r)
      do i = 1, 10
        r = r + 1
      end do
    !$omp end parallel do
  end subroutine foo
end module foo_module