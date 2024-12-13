module foo_module
contains
    pure subroutine foo()
        error stop "failed"
    end subroutine foo
end module foo_module