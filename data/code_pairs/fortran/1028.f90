! permanent_arrays.f90
module permanent_arrays
  implicit none
  integer, parameter :: double = selected_real_kind(15, 307)
  integer, dimension (:), allocatable :: labels
  real(double), dimension (:), allocatable :: xparam
  character(len=4), dimension (:), allocatable :: simbol
end module permanent_arrays

program test_permanent_arrays
  use permanent_arrays
  implicit none

  allocate(labels(5))
  allocate(xparam(5))
  allocate(simbol(2))

  labels = (/1, 2, 3, 4, 5/)
  xparam = (/1.0_double, 2.0_double, 3.0_double, 4.0_double, 5.0_double/)
  simbol(1) = "H   "
  simbol(2) = "He  "

  print *, "Labels: ", labels
  print *, "XParam: ", xparam
  print *, "Simbol: ", simbol

  deallocate(labels)
  deallocate(xparam)
  deallocate(simbol)
end program test_permanent_arrays