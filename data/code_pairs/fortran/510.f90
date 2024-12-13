program test_iranfeven
    implicit none

    ! Function prototype
    integer :: iranfeven
    integer :: i, result

    ! Test cases
    do i = -1, 4
        result = iranfeven(i)
        print *, "iranfeven(", i, ") = ", result
    end do

end program test_iranfeven

function iranfeven(N)
    integer :: N
    integer :: iranfeven

    if (mod(N, 2) == 0) then
        iranfeven = 1
    else
        iranfeven = 0
    endif
end function iranfeven