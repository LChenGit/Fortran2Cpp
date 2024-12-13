module gsbpmod
    implicit none
    integer :: nclx1, ncly1
    integer, allocatable :: lstpl(:), lstpm(:)

contains

    subroutine initialize(x1, y1)
        integer, intent(in) :: x1, y1
        nclx1 = x1
        ncly1 = y1
        allocate(lstpl(nclx1))
        allocate(lstpm(ncly1))
        lstpl = 1
        lstpm = 2
    end subroutine initialize

    subroutine incrementArrays()
        integer :: i
        do i = 1, nclx1
            lstpl(i) = lstpl(i) + 1
        end do
        do i = 1, ncly1
            lstpm(i) = lstpm(i) + 1
        end do
    end subroutine incrementArrays

end module gsbpmod