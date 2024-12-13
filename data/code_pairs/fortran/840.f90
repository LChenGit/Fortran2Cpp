! Main program to demonstrate dynamic memory management in Fortran
program deallocate_demo
    implicit none
    integer, allocatable :: A, B(:)
    integer :: stat
    character(len=200) :: str
    character(len=5) :: sstr

    str = repeat('X', len(str))
    deallocate(A, stat=stat, errmsg=str)
    if (stat /= 0 .and. str == "Attempt to deallocate an unallocated object") then
        print *, "Attempt to deallocate A caught as expected."
    else
        call abort()
    end if

    allocate(B(10), stat=stat)  ! For the sake of the example, ensure B is allocated
    if (stat /= 0) then
        print *, "Allocation of B failed."
        stop
    end if

    str = repeat('Y', len(str))
    deallocate(B, stat=stat, errmsg=str)
    if (stat == 0) then
        print *, "B deallocated successfully."
    else
        call abort()
    end if

    sstr = repeat('Q', len(sstr))
    deallocate(A, stat=stat, errmsg=sstr)
    if (stat /= 0 .and. sstr == "Attem") then
        print *, "Attempt to deallocate A caught with short message as expected."
    else
        call abort()
    end if

    sstr = repeat('P', len(sstr))
    deallocate(B, stat=stat, errmsg=sstr)
    if (stat /= 0 .and. sstr == "Attem") then
        print *, "Attempt to deallocate B caught with short message as expected."
    else
        call abort()
    end if

end program deallocate_demo