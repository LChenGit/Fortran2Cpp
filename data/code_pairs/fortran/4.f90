program main
    implicit none
    integer :: me, n1, n2, n3, i
    integer, dimension(20) :: a

    ! Assuming we simulate the process ID (me)
    ! Note: In a real parallel environment, you would obtain 'me' using MPI or another parallel library
    do me = 1, 4
        ! Initialize array based on the simulated process rank
        do i = 1, 20
            a(i) = i * me
        end do

        ! Simulate fetching values from the array as if they were from different nodes
        ! Here, we just reuse the values for demonstration purposes
        n1 = a(10)
        n2 = a(10)
        n3 = a(10)

        ! Print the results
        write(*,*) "me,n1,n2,n3=", me, n1, n2, n3
    end do
end program main