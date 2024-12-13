module m
  implicit none
  type :: t
    ! Members would be added here if necessary
  end type t
contains
  type(t) function foo()
    foo = t() ! Constructs an instance of t
  end function foo
end module m