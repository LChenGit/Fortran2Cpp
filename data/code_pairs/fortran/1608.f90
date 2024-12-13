! D.f90
module D

contains

subroutine f_d()
  write (6,*) "f_d()"
end subroutine f_d

end module D

! TestD.f90
program test
  use D
  call f_d()
end program test