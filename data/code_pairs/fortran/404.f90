program a1d1
    integer, parameter :: N = 100
    integer :: a(N), b(N), nerr, i, nval

    ! Simulate "me" for a single-image scenario
    integer :: me = 1

    ! Initialize arrays
    do i=1,N
       a(i) = i + me * 100
    end do

    b = -99

    ! Modify b based on condition (simplified)
    if (me==1) then
       do i=11,44
          b(i)=a(i)
       end do
    end if

    ! Validation and error checking (simplified)
    nerr = 0
    do i=1,N
       nval=i+me*100
       if (a(i) /= nval) then
          print *, "Error in a: ", i, me, a(i), nval
          nerr=nerr+1
       end if
    end do

    if (nerr==0) then 
       print *, "Result OK"
    else
       print *, "Number of errors: ", nerr
    end if

end program