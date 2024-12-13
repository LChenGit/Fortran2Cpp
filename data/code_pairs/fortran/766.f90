! kinds_module.f90
module kinds_module
  implicit none
contains
  subroutine test_double()
    print *, "test_double called"
  end subroutine test_double

  subroutine test_complex()
    print *, "test_complex called"
  end subroutine test_complex
end module kinds_module

! bhmie_module.f90
module bhmie_module
  implicit none
contains
  subroutine bhmie_driver()
    print *, "bhmie_driver called"
  end subroutine bhmie_driver
end module bhmie_module

! dmiess_module.f90
module dmiess_module
  implicit none
contains
  subroutine dmiess_driver()
    print *, "dmiess_driver called"
  end subroutine dmiess_driver
end module dmiess_module

! dmilay_module.f90
module dmilay_module
  implicit none
contains
  subroutine dmilay_driver()
    print *, "dmilay_driver called"
  end subroutine dmilay_driver
end module dmilay_module

! test_modules.f90
program test_modules
  use kinds_module
  use bhmie_module
  use dmiess_module
  use dmilay_module
  implicit none

  call test_double()
  call test_complex()
  call bhmie_driver()
  call dmiess_driver()
  call dmilay_driver()

end program test_modules