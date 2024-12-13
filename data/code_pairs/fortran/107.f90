module c_funloc_tests_3
  implicit none
contains
  function ffunc(j) bind(c)
    use iso_c_binding, only: c_funptr, c_int
    integer(c_int)        :: ffunc
    integer(c_int), value :: j
    ffunc = -17_c_int * j
  end function ffunc
end module c_funloc_tests_3