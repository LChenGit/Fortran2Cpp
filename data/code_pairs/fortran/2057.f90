! umpc_user.f90
program test_umpc_user
    implicit none
    integer, parameter :: n = 5
    real(8) :: x(3,n), u(3,n), f, a(n), force
    integer :: jdof(n), iit, idiscon
    integer :: i

    ! Initialize some input values for demonstration purposes
    do i = 1, n
        a(i) = i * 1.0d0
    end do
    iit = 1
    idiscon = 1

    ! Call the subroutine
    call umpc_user(x, u, f, a, jdof, n, force, iit, idiscon)

    ! Output the result
    print *, 'Force:', force

contains

    subroutine umpc_user(x, u, f, a, jdof, n, force, iit, idiscon)
        implicit none
        integer, intent(in) :: jdof(*), n, iit, idiscon
        real(8), intent(in) :: x(3,*), u(3,*), f, a(*)
        real(8), intent(out) :: force
        integer :: i

        force = 0.0d0
        do i = 1, n
            force = force + a(i)
        end do
    end subroutine umpc_user

end program test_umpc_user