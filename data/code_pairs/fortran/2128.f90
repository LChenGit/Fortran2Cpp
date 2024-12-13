module foo_module
  implicit none
contains
  subroutine foo()
    print *, 'foo() called'
  end subroutine foo
end module foo_module