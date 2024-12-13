program test
    implicit none
    integer :: j, i
    
    j = 0
    do i = 1, 3
        if (i == 2) then
            cycle
        endif
        j = j + 1
    end do
    if (j /= 2) stop 1
end program test