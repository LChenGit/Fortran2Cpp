program DRB078_taskdep2_orig_no
    use omp_lib
    implicit none

    integer :: i
    i = 0

    !$omp parallel
        !$omp single
            !$omp task depend (out:i)
                call sleep(3)
                i=3
            !$omp end task
            !$omp task depend (out:i)
                i=2
            !$omp end task
        !$omp end single
    !$omp end parallel

    if (i /=2 ) then
        print 100, i
        100 format (i3)
    end if
end program
