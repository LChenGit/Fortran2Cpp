program cpu_timer
    implicit none
    real :: start, finish, elapsed
    call cpu_time(start)
    ! Your code here (This can be any operation you wish to measure the CPU time for)
    call cpu_time(finish)
    elapsed = finish - start
    print *, "CPU Time: ", elapsed, " seconds"
end program cpu_timer