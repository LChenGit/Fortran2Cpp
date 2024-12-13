module foo_mod
  implicit none
  type, abstract :: foo
    integer :: i
  contains
    procedure, pass :: doit
    procedure, pass :: getit
    generic :: do => doit
    generic :: get => getit
  end type foo

  abstract interface
    subroutine doit(a)
      import :: foo
      class(foo), intent(inout) :: a
    end subroutine doit

    function getit(a) result(res)
      import :: foo
      class(foo), intent(in) :: a
      integer :: res
    end function getit
  end interface
end module foo_mod

module foo2_mod
  use foo_mod
  implicit none
  type, extends(foo) :: foo2
    integer :: j
  contains
    procedure :: doit => doit2
    procedure :: getit => getit2
  end type foo2

contains
  subroutine doit2(a)
    class(foo2), intent(inout) :: a
    a%i = 2
    a%j = 3
    print *, "FOO2::doit2 derived version"
  end subroutine doit2

  function getit2(a) result(res)
    class(foo2), intent(in) :: a
    integer :: res
    res = a%j
  end function getit2
end module foo2_mod

program testd15
  use foo2_mod
  type(foo2) :: af2

  call af2%do()
  if (af2%i /= 2) call abort
  if (af2%get() /= 3) call abort

  print *, "All tests passed successfully."
end program testd15