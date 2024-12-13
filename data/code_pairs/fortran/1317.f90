! file: handlers.f90
module handlers
  implicit none
contains
  subroutine onClosing()
    print *, "Closing event triggered."
  end subroutine onClosing
end module handlers

! file: main.f90
program main
  use handlers
  implicit none
  call onClosing()
end program main