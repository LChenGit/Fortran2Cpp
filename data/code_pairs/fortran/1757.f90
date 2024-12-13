module foo_mod
  implicit none
contains

  subroutine foo(x)
    integer, intent(in) :: x(:)
    integer :: sum, i
    sum = 0
    do i = 1, size(x)
       sum = sum + x(i)
    end do
    print *, 'Sum = ', sum
  end subroutine foo

end module foo_mod