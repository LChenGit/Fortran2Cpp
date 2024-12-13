program test_transfer
implicit none

    ! Variables
    integer :: i
    logical :: b

    ! Test transferring int to bool
    i = 0
    b = transfer(i, .true.)
    print *, 'Transfer int 0 to bool:', b

    ! Test transferring nonzero int to bool
    i = -1
    b = transfer(i, .true.)
    print *, 'Transfer int -1 to bool:', b

end program test_transfer