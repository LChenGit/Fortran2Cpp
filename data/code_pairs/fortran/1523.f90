subroutine foo(a)
    integer :: a
    write(*,*) "Hello from Fortran!!"
    write(*,*) "input value a=",a
end subroutine foo

subroutine foovec(a)
    integer, dimension(10) :: a
    write(*,*) "Hello from Fortran!!"
    write(*,*) "input value avec=",a
end subroutine foovec