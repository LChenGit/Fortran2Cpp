module finalize_mod
  implicit none
  private
  public :: finalize

contains

  subroutine finalize_dyn()
    print *, "finalize_dyn called"
  end subroutine finalize_dyn

  subroutine finalize_phy()
    print *, "finalize_phy called"
  end subroutine finalize_phy

  subroutine shtns_destroy()
    print *, "shtns_destroy called"
  end subroutine shtns_destroy

  subroutine finalize()
    call finalize_dyn()
    call finalize_phy()
    call shtns_destroy()
    print *, "Finalize subroutine executed successfully."
  end subroutine finalize

end module finalize_mod