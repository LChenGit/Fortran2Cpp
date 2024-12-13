module juslin_scr
  implicit none
contains
  subroutine init_juslin(success)
    logical, intent(out) :: success
    print *, "Juslin module initialized."
    success = .true.
  end subroutine init_juslin
end module juslin_scr