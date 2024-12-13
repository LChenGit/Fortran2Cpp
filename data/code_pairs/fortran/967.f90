subroutine flood(zslice, wet, dry, x, y, dmax, flooded_zslice, im, jm, nbwet, nbdry)
  implicit none
  integer, intent(in) :: im, jm, nbwet, nbdry, dmax
  real(8), dimension(im,jm), intent(in) :: zslice, x, y
  real(8), dimension(im,jm), intent(out) :: flooded_zslice
  integer, dimension(nbwet,2), intent(in) :: wet
  integer, dimension(nbdry,2), intent(in) :: dry
  real(8), dimension(nbwet) :: d
  integer :: n, m, dmin_idx, idry, jdry, iwet, jwet, iclose, jclose
  
  flooded_zslice = zslice
  
  do n = 1, nbdry
    idry = dry(n, 1)
    jdry = dry(n, 2)
    do m = 1, nbwet
      iwet = wet(m, 1)
      jwet = wet(m, 2)
      d(m) = sqrt((x(idry, jdry) - x(iwet, jwet))**2 + (y(idry, jdry) - y(iwet, jwet))**2)
    end do
    dmin_idx = minloc(d, 1)
    iclose = wet(dmin_idx, 1)
    jclose = wet(dmin_idx, 2)
    if (dmax == 0 .or. d(dmin_idx) <= dmax) then
      flooded_zslice(idry, jdry) = zslice(iclose, jclose)
    end if
  end do
end subroutine flood