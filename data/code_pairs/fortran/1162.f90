subroutine correct_flux(n, velocity, area, flux_in, flux_out, correction)
  implicit none
  integer, intent(in) :: n
  real, dimension(n), intent(in) :: velocity, area, flux_in
  real, dimension(n), intent(out) :: flux_out
  real, intent(in) :: correction
  integer :: i

  do i = 1, n
     if (velocity(i) > 0.0) then
        flux_out(i) = flux_in(i) * area(i) * correction
     else
        flux_out(i) = flux_in(i)
     end if
  end do
end subroutine correct_flux