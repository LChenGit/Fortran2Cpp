program three_body
    implicit none
    integer, parameter ::  n = 2, d = 2
    real, dimension(n,d) :: x_hq

    call step(x_hq)
    print *, "Matrix x_hq filled with:"
    print *, x_hq

contains

    subroutine step(x)
        real, dimension(:,:), intent(inout) :: x
        x = 1.0
    end subroutine step

end program three_body