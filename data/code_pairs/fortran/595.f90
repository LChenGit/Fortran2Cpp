subroutine switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
  implicit none
  real :: sw, dsw, z, p1, ip1, zmemb1, zmemb2
  real :: delz, delzp1

  if (z.ge.(zmemb2+p1).or.z.le.(zmemb1-p1)) then 
    sw = 0.0
    dsw = 0.0
  else
    if (z.gt.zmemb2) then 
      delz = z - zmemb2
      delzp1 = delz * ip1
      sw = 1.0 + (2.0*delzp1-3.0)*delzp1**2
      dsw = -6.0*(delzp1-1.0)*ip1*delzp1
    elseif (z.lt.zmemb1) then 
      delz = zmemb1 - z
      delzp1 = delz * ip1
      sw = 1.0 + (2.0*delzp1-3.0)*delzp1**2
      dsw = 6.0*(delzp1-1.0)*ip1*delzp1
    else
      sw = 1.0
      dsw = 0.0
    endif
  endif
end subroutine switch1