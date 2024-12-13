module m
  use iso_c_binding
  implicit none
  integer(c_int), save, bind(C, name="a_m") :: a = 5
end module m