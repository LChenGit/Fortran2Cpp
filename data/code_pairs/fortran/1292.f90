program fileOperations
    implicit none
    integer :: iounit, status

    ! Open a file named "99" for writing, creating it if it doesn't exist
    open(newunit=iounit, file='99', status='replace', action='write')
    write(iounit,*) 'Testing file creation.'
    close(iounit)

    ! Check if the file exists
    inquire(file='99', exist=status)
    if (status == 1) then
        print *, "File '99' exists after creation."
    else
        print *, "File '99' does not exist."
    endif

    ! Delete the file
    open(newunit=iounit, file='99', status='replace', action='delete')
    close(iounit)

    ! Check again if the file exists
    inquire(file='99', exist=status)
    if (status == 1) then
        print *, "File '99' exists after deletion."
    else
        print *, "File '99' does not exist after deletion."
    endif

end program fileOperations