program demo

    real(kind=8) :: x(1001),y(1001)
    integer :: j

    do j=1,1001
        x(j) = -20.d0 + (j-1)*40.d0/1000.d0
        if (x(j) == 0.d0) then
            y(j) = 1.d0  ! Handling the division by zero case
        else
            y(j) = sin(x(j)) / x(j)
        endif
    enddo
            
    print *, "The max value of y is ",maxval(y)

    print *, "x(501) is ", x(501)
    print *, "y(501) is ", y(501)
        
end program demo