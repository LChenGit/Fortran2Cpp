! This program is a simple demonstration and doesn't include explicit testing code.
program main
    implicit none
    character(len=128) :: arr(2)

    arr = [ "abc", "foobar" ] ! Initialize the array

    ! Display the array elements
    print *, "Array contents:"
    print *, trim(arr(1))
    print *, trim(arr(2))
end program main