! kinds.f90
module kinds
    implicit none
    integer, parameter :: dp = selected_real_kind(15, 307)
end module kinds

! dot_module.f90
module dot_module
    use kinds, only: dp
    implicit none
contains
    real(kind=dp) function dot(x, y, n)
        integer, intent(in) :: n
        real(kind=dp), intent(in) :: x(n)
        real(kind=dp), intent(in) :: y(n)
        dot = sum(x(:n) * y(:n))
    end function dot
end module dot_module

! test_dot.f90
program test_dot
    use kinds, only: dp
    use dot_module, only: dot
    implicit none
    real(kind=dp) :: result
    real(kind=dp), dimension(3) :: x = [1.0_dp, 2.0_dp, 3.0_dp]
    real(kind=dp), dimension(3) :: y = [4.0_dp, 5.0_dp, 6.0_dp]
    integer :: n = 3

    result = dot(x, y, n)
    print *, "Dot product is:", result
    ! Expected output: Dot product is: 32.000000000000000
end program test_dot