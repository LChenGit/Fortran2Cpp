module Foo_mod
  implicit none
contains
  ! This is just a declaration; the actual implementation is in the submodule.
end module Foo_mod

submodule(Foo_mod) Foo_smod
  use, intrinsic :: iso_c_binding
contains
  subroutine runFoo4C(ndim) bind(C, name="runFoo")
    implicit none
    integer(c_int32_t), intent(in) :: ndim
    print *, "Running runFoo with ndim =", ndim
  end subroutine runFoo4C
end submodule Foo_smod