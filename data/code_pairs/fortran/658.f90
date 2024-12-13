module fittingmod
  use, intrinsic :: iso_c_binding, only: c_double
  implicit none
  integer, pointer :: np2
  real(c_double), dimension(:), pointer :: xp2, yp2, ep2, th2, xpos2, ypos2
end module fittingmod