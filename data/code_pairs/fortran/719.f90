module panel_utilities
  implicit none
contains
  logical function Panel_Diagonal(Ilo, Ihi, Jlo, Jhi, Dlo, Dhi)
    integer, intent(in) :: Ilo, Ihi, Jlo, Jhi
    integer, intent(out) :: Dlo, Dhi
    integer :: UR, LL

    UR = Ihi - Jlo
    LL = Ilo - Jhi

    if (UR * LL > 0) then
      Panel_Diagonal = .false.
      return
    else
      Panel_Diagonal = .true.
    endif

    Dlo = max(Ilo, Jlo)
    Dhi = min(Ihi, Jhi)
  end function Panel_Diagonal
end module panel_utilities