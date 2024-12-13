! file: update_y.f90
module update_y_module
    implicit none
contains
    subroutine update_y(y, ekk, tiltc, tilts, i)
        real, intent(inout) :: y(2)
        real, intent(in) :: ekk, tiltc(:), tilts(:)
        integer, intent(in) :: i

        y(1) = y(1) + ekk * tiltc(i)
        y(2) = y(2) + ekk * tilts(i)
    end subroutine update_y
end module update_y_module