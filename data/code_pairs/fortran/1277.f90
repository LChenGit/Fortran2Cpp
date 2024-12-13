program main
  implicit none

  call sub

  print *, "OK"

contains

  subroutine sub
    real, allocatable :: c(:), d(:,:), e(:)
    allocate(c(10), d(2,5), e(10))
    deallocate(c, d, e)
  end subroutine sub

end program main