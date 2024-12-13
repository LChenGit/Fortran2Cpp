program main
implicit none

! Call the subroutine to mimic the original program's print functionality
call printMessage()

contains

    subroutine printMessage()
        ! This subroutine mimics the original program's functionality
        print *, 'ok'
    end subroutine printMessage

end program main