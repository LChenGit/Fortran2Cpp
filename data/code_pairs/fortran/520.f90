program hello_goodbye
implicit none
call say_hello
call say_goodbye
contains
    subroutine say_hello
        write(*,*) 'Hello, World!'
    end subroutine say_hello

    subroutine say_goodbye
        write(*,*) 'Goodbye, World!'
    end subroutine say_goodbye
end program hello_goodbye