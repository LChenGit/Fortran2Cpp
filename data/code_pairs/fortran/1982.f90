program test_ampersands
    implicit none
    character(len=70) :: str

    str = 'Print rather a lot of ampersands &&&&&' // &
         '&&&&&' // &
         '&&&&&'
    if (len(trim(str)) /= 44 .or. str /= 'Print rather a lot of ampersands &&&&&&&&&&&') then
        call abort()
    end if
end program test_ampersands