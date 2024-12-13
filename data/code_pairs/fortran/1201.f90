! main_operation.f90
program main
    implicit none
    real*8, dimension(1000000000) :: X
    real*8, dimension(1000000000) :: Y
    real*8, dimension(10) :: runtimes
    double precision t1, t2, meanruntimes
    integer i

    do i = 1, 10
        X(:) = 1.0
        Y(:) = 1.0
        call cpu_time(t1)
        X = X + Y + Y
        call cpu_time(t2)
        runtimes(i) = t2 - t1
    end do
    meanruntimes = sum(runtimes) / 10.0
    print *, 'mean run time in seconds'
    print *, meanruntimes
end program main