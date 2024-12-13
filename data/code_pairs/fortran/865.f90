module foo_mod
  implicit none
  private
  public :: foo, foo2

  type :: foo
    integer :: i
  contains
    procedure, pass :: doit
    procedure, pass :: getit
  end type foo

  type, extends(foo) :: foo2
    integer :: j
  contains
    procedure, pass :: doit => doit2
    procedure, pass :: getit => getit2
  end type foo2

contains
  subroutine doit(this)
    class(foo), intent(inout) :: this
    this%i = 1
  end subroutine doit

  function getit(this) result(res)
    class(foo), intent(in) :: this
    integer :: res
    res = this%i
  end function getit

  subroutine doit2(this)
    class(foo2), intent(inout) :: this
    this%i = 2
    this%j = 3
  end subroutine doit2

  function getit2(this) result(res)
    class(foo2), intent(in) :: this
    integer :: res
    res = this%j
  end function getit2

end module foo_mod