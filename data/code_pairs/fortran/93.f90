program builtinfcns
    implicit none
    real :: pi, x, y

    pi = acos(-1.0)
    x = cos(pi)
    y = sqrt(exp(log(pi)))**2

    print *, "pi = ", pi
    print *, "x = ", x
    print *, "y = ", y
end program builtinfcns