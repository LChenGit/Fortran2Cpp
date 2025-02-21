real function add(a, b) result(c)
    real, intent(in) :: a, b
    c = a + b
end function add

program main
    real :: a, b, c
    a = 5.0
    b = 10.0
    c = add(a, b)
    print *, "The sum is: ", c
end program main