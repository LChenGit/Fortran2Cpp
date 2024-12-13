! main.f90
program main
    real :: x
    namelist /mynml/ x
    x = 1
    print *, "x = ", x
end program main