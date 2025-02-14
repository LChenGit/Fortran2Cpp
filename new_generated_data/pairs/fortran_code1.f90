! Define a module for utility subroutines
module util_module
    implicit none

contains
    subroutine foo(ii)
        integer, intent(in) :: ii
        integer :: b
        
        b = ii
        call bar(ii, b)
        
    end subroutine foo

    subroutine bar(a, b)
        integer, intent(in) :: a, b
        
        if (a /= b) then
            write (*,*) "Error: a /= b"
            write (*,*) "a =", a
            write (*,*) "b =", b
            stop 1  ! Stop program with error code
        end if
        
    end subroutine bar

end module util_module

! Main program
program main
    use util_module
    
    call foo(7)
    call foo(0)
    call foo(127)
    call foo(-128)
    
    write (*,*) "All tests passed!"
    
end program main