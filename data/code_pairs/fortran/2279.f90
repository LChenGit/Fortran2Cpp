! h5global.f90
module h5global
  implicit none
  integer :: h5p_default_f, h5p_flags
  equivalence(h5p_flags, h5p_default_f)
end module h5global