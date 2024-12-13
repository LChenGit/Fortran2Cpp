program test_timestamp
    implicit none

contains

    subroutine timestamp(d, m, y, h, n, s)
        implicit none
        integer, intent(in) :: d, m, y, h, n, s
        character(len=9), dimension(12) :: month = [ &
             'January  ', 'February ', 'March    ', 'April    ', &
             'May      ', 'June     ', 'July     ', 'August   ', &
             'September', 'October  ', 'November ', 'December ' ]
        character(len=20) :: ampm
        character(len=60) :: formatted_time
        integer :: hh

        if (h >= 12) then
            if (h > 12) then
                hh = h - 12
            else
                hh = h
            end if
            if (h == 12 .and. n == 0 .and. s == 0) then
                ampm = 'Noon'
            else
                ampm = 'PM'
            end if
        else
            hh = h
            if (h == 0) then
                hh = 12
                ampm = 'Midnight'
            else
                ampm = 'AM'
            end if
        end if

        write(formatted_time, '(I2, " ", A, " ", I4, " ", I2, ":", I2.2, ":", I2.2, " ", A)') &
             d, trim(month(m)), y, hh, n, s, trim(ampm)

        print *, 'Formatted Time: ', trim(formatted_time)
    end subroutine timestamp

    call timestamp(15, 7, 2023, 12, 0, 0)
    call timestamp(16, 7, 2023, 0, 0, 0)
    ! Add additional calls to subroutine for more test cases as needed

end program test_timestamp