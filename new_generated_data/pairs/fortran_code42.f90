module kinds
    implicit none

    integer, parameter :: ik4 = selected_int_kind(4)    ! 4-byte integer
    integer, parameter :: ik8 = selected_int_kind(8)    ! 8-byte integer

    integer, parameter :: rk4 = selected_real_kind(6)    ! 4-byte real (single precision)
    integer, parameter :: rk8 = selected_real_kind(15)   ! 8-byte real (double precision)

end module kinds

program test
    use kinds
    implicit none

    integer(ik4) :: i
    real(rk8) :: x
    x = 3.141592653589793_rk8  ! Assign using kind rk8

    ! Initialize variables
    i = 0   ! Initialize integer variable

    print *, 'Hello, Fortran!'
    print *, 'Integer:', i
    print *, 'Real:', x

end program test

! The original entropy and entropy_s subroutines are here...

subroutine entropy(f, temp, nx, ent)
    use kinds
    implicit none
    integer :: nx
    real(rk8)  f(nx), temp, ent
    integer :: i
    real(rk8) fm
    real(rk8), parameter :: eps = 1.0e-10
    ent = 0.0_rk8
    do i = 1, nx
        fm = 0.5_rk8 * f(i)
        ent = ent + fm * log(eps + fm) + (1.0_rk8 - fm) * log(eps + 1.0_rk8 - fm)
    end do
    ent = -2.0_rk8 * temp * ent
    return
end subroutine entropy

subroutine entropy_s(f, temp, nx, ent)
    use kinds
    implicit none
    integer :: nx
    integer :: i
    real(rk8)  f(nx), temp, ent, fm, eps
    parameter(eps = 1.0e-10)
    ent = 0.0_rk8
    do i = 1, nx
        fm = 0.5_rk8 * f(i)
        ent = ent + fm * log(eps + fm) + (1.0_rk8 - fm) * log(eps + 1.0_rk8 - fm)
    end do
    ent = -2.0_rk8 * temp * ent
    return
end subroutine entropy_s