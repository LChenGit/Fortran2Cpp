program hello_world
    implicit none
    call print_hello_world
end program hello_world

subroutine print_hello_world
    implicit none
    print *, 'hello world'
end subroutine print_hello_world