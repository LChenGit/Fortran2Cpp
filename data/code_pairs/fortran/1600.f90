program main
  implicit none
  integer, parameter         :: n = 10
  integer, dimension (0:n-1) :: a, b, c
  integer                    :: i

  do i = 0, n - 1
     a(i) = i * 2
  end do

  do i = 0, n - 1
     b(i) = i * 4
  end do

  do i = 0, n - 1
     c(i) = a(i) + b(i)
  end do

  do i = 0, n - 1
     if (c(i) .ne. a(i) + b(i)) call abort
  end do

end program main