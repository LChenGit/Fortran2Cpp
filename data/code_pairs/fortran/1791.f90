program read_binary
    implicit none
    integer :: iounit, ios
    real :: num

    ! Attempt to open a binary file for reading
    open(newunit=iounit, file='data.bin', status='old', action='read', form='unformatted', access='sequential', iostat=ios)
    
    ! Check if the file was successfully opened
    if (ios /= 0) then
        print *, 'Cannot open file!'
        stop
    end if

    ! Attempt to read a floating-point number from the file
    read(iounit, iostat=ios) num
    if (ios /= 0) then
        print *, 'Read error!'
        stop
    else
        print *, 'Read number: ', num
    end if

    ! Close the file
    close(iounit)
end program read_binary