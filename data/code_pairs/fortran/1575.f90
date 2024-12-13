program pd_example
    implicit none
    integer, dimension(1:12) :: A, C
    integer :: i

    ! Initialize array A with values 1 to 12
    A = (/ (I, I = 1, 12) /)
    ! Increment each element by 1 and assign to C
    C = A + 1

    ! Print elements of C
    do i = 1, 12
        print *, "C(", i, ") = ", C(i)
    end do
end program pd_example