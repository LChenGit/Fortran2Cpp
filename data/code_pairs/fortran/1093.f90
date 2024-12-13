module m
implicit none

contains

  subroutine sub(v)
    integer, allocatable, intent(out) :: v(:)
    if (allocated(v)) deallocate(v)
  end subroutine sub

end module m