program conversion_tipos
    integer :: int = 6
    real :: r_var = 3.5
    complex :: z = (2, 5.9)

    print *, "Complex + integer: ", z + int
    print *, "Complex + real: ", r_var + z
    print *, "Real + integer: ", r_var + int
end program conversion_tipos