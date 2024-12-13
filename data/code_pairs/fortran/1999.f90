module mod_foo
  implicit none
contains
  pure subroutine foo()
    error stop "failed"
  end subroutine foo
end module mod_foo