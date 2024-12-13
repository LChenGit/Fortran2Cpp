! error.f90
subroutine error(function_name, message, value, level)
    implicit none
    character(len=*), intent(in) :: function_name
    character(len=*), intent(in) :: message
    real(8), intent(in) :: value
    integer, intent(in) :: level

    if ((level .lt. 1) .or. (level .gt. 3)) then
        print *, '*** Error in Subroutine error:'
        print *, '*** Message: Wrong Errorlevel'
        print *, '*** Related Value: ', level
    end if

    if (level .eq. 1) then
        print *, '*** Warning in Subroutine ', trim(function_name), ':'
    elseif (level .eq. 2) then
        print *, '*** Error in Subroutine ', trim(function_name), ':'
    elseif (level .eq. 3) then
        print *, '*** Fatal Error in Subroutine ', trim(function_name), ':'
    end if
    print *, '*** Message: ', trim(message)
    print *, '*** Related Value: ', value

    if (level .ge. 3) then
        print *, '*** Program stopped.'
        stop 137
    end if
end subroutine error