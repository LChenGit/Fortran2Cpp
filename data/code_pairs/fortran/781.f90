program nutest
    implicit none
    integer :: ios
    logical :: l

    open(unit=10, file="foo_open_negative_unit_1.txt", status="replace", iostat=ios)
    if (ios /= 0) then
        print *, "Error opening file foo_open_negative_unit_1.txt"
        stop
    endif
    close(10, status="delete")

    inquire(file="foo_open_negative_unit_1.txt", exist=l)
    if (l) then
        print *, "File foo_open_negative_unit_1.txt should have been deleted."
        stop
    endif

    print *, "Fortran program operations completed."
end program nutest