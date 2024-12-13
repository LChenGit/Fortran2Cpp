module test_mod
    implicit none
contains
    pure real function add(i,j,k)
        integer, intent(in) :: i,j,k
        add = real(i+j+k) + 1.0
    end function add

    pure real function add2(i,j,k)
        integer, intent(in) :: i,j,k
        add2 = real(i+j+k)
    end function add2

    subroutine check_err(a, s)
        real, dimension(:,:), intent(in) :: a
        real, intent(in) :: s
        if (abs(sum(a) - s) > 1e-5) then
            print *, "Error detected"
            stop
        end if
    end subroutine check_err
end module test_mod