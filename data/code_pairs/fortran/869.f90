module BoxMullerMod
    implicit none
contains
    subroutine boxMuller(x, y)
        real, intent(out) :: x, y
        real :: u1, u2, r, theta
        call random_seed()
        call random_number(u1)
        call random_number(u2)
        r = sqrt(-2.0 * log(u1))
        theta = 2.0 * 3.14159265358979323846 * u2
        x = r * cos(theta)
        y = r * sin(theta)
    end subroutine boxMuller
end module BoxMullerMod