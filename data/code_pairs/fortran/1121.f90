program decl_var

implicit none

real :: var_real
integer :: var_int
complex :: var_cplx
logical :: var_log
character :: var_char
character(len=80) :: mnsj

var_real = 3.141517
var_int = 6
var_cplx = (1, 1)
var_cplx = cmplx(2, -4)
var_log = .true.
var_char = 'a'
mnsj = "Bienvenidos al curso de Fortran de PROTECO!"

print *, var_real
print *, var_int
print *, var_cplx
print *, var_log
print *, var_char
print *, mnsj

end program decl_var