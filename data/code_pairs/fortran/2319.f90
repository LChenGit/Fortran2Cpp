module fortran_module
  implicit none
contains
  subroutine makeobj(n)
    integer :: n
    print *, "makeobj called with n=", n
  end subroutine makeobj

  subroutine makeob(n)
    integer :: n
    print *, "makeob called with n=", n
  end subroutine makeob

  subroutine closeobj
    print *, "closeobj called"
  end subroutine closeobj

  subroutine closeo
    print *, "closeo called"
  end subroutine closeo

  subroutine delobj(n)
    integer :: n
    print *, "delobj called with n=", n
  end subroutine delobj

  function genobj() result(n)
    integer :: n
    n = 42
    print *, "genobj called"
  end function genobj

  function getopenobj() result(n)
    integer :: n
    n = 99
    print *, "getopenobj called"
  end function getopenobj

  function getope() result(n)
    integer :: n
    n = 99
    print *, "getope called"
  end function getope

  subroutine callobj(n)
    integer :: n
    print *, "callobj called with n=", n
  end subroutine callobj

  subroutine callob(n)
    integer :: n
    print *, "callob called with n=", n
  end subroutine callob

  function isobj(n) result(res)
    integer :: n
    integer :: res
    if (mod(n, 2) == 0) then
      res = 1
    else
      res = 0
    endif
    print *, "isobj called with n=", n
  end function isobj
end module fortran_module