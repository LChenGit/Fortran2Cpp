module mod_t
  implicit none
  type :: t
    integer :: x
  end type t

contains
  logical function t_foo(this, other)
    class(t), intent(in) :: this, other
    t_foo = .false.
  end function t_foo

  logical function t_bar(this, other)
    class(t), intent(in) :: this, other
    t_bar = .false.
  end function t_bar
end module mod_t