PROGRAM main

    character *7 str
    integer array(7), i

    str = 'abcdefg'
    do i = 1, 7
      array(i) = i
    end do

    ! Output to manually verify
    write (*, *) str(2:4)
    write (*, *) str(:3)
    write (*, *) str(5:)
    write (*, *) str(:)

END PROGRAM main