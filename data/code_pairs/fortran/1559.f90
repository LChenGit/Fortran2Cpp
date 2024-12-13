module greet_mod
    implicit none
contains
    subroutine greet(name)
        character(len=*), intent(in) :: name
        print *, 'Hello, ', trim(name), '!'
    end subroutine greet
end module greet_mod