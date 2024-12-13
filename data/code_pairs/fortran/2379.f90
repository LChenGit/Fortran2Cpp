program main
    implicit none
    character(len=5) :: x
    integer :: i

    x = '12345'
    i = index(x, 'blablabl')
    if (i .ne. 0) then
        call abort
    end if
end program main