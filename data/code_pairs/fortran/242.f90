module foo_mod
contains
  subroutine foo(a)
    integer, intent(out) :: a(30)
    integer :: i

    ! Using OpenMP to parallelize the loop
    !$omp parallel for private(i)
    do i = 1, 30
      if (mod(i,2)==0) then
        a(i) = 5
      else if (i <= 15) then
        a(i) = 2
      else
        a(i) = 1
      end if
    end do
    !$omp end parallel for
  end subroutine foo
end module foo_mod