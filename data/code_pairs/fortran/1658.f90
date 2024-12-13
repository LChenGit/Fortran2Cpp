PROGRAM subarray
    implicit none
    character(len=7) :: str
    integer :: array(7)
    integer :: i

    str = 'abcdefg'
    do i = 1, 7
      array(i) = i
    end do

    print *, str(2:4)
    print *, str(:3)
    print *, str(5:)
    print *, str(:)
END PROGRAM subarray