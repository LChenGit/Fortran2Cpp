module findMaxMod
    implicit none
contains
    function findMax(A, N) result(BIGA)
        double precision, intent(in) :: A(:)
        integer, intent(in) :: N
        double precision :: BIGA
        integer :: i

        ! Handle empty array case
        if (N <= 0) then
            BIGA = -1.0e30  ! Placeholder for NaN in this context
            return
        end if

        BIGA = A(1)
        do i = 2, N
            if (BIGA < A(i)) then
                BIGA = A(i)
            end if
        end do
    end function findMax
end module findMaxMod