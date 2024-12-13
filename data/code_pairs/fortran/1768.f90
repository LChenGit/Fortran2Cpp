module bessel_module
implicit none
contains

! Computes Bessel functions for a given lmax and x
subroutine zbessela(lmax, x, a)
    implicit none
    integer, intent(in) :: lmax
    real(8), intent(in) :: x
    real(8), intent(out) :: a(0:lmax)
    integer :: l
    real(8) :: xi, t1, t2

    if ((lmax < 0) .or. (lmax > 50)) then
        print *, 'Error(zbessela): lmax out of range:', lmax
        stop
    endif
    if ((x < 0.d0) .or. (x > 1.d8)) then
        print *, 'Error(zbessela): x out of range:', x
        stop
    endif

    ! Special handling for very small x values
    if (x < 1.d-7) then
        a(0) = 1.d0
        t1 = 1.d0
        t2 = 1.d0
        do l = 1, lmax
            t1 = t1 / dble(2*l + 1)
            t2 = -t2 * x
            a(l) = t2 * t1
        end do
        return
    endif

    ! General case
    a(0) = 1.d0
    do l = 1, lmax
        a(l) = a(l-1) * dble(l) / (2.d0 * l + 1.d0) * (-x)
    end do
end subroutine zbessela

end module bessel_module

program test_zbessela
    use bessel_module
    implicit none
    integer, parameter :: lmax = 5
    real(8), allocatable :: a(:)
    real(8) :: x
    integer :: i

    allocate(a(0:lmax))
    x = 0.5d0

    call zbessela(lmax, x, a)

    do i = 0, lmax
        print *, 'a(', i, ') =', a(i)
    end do
end program test_zbessela