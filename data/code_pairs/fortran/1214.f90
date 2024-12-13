module arrayOps
    implicit none
    integer, parameter :: dimx = 8, dimy = 6
    real, dimension(dimx, dimy) :: ftab
contains
    subroutine filltab()
        integer :: x, y

        do x = 1, dimx
            do y = 1, dimy
                ftab(x, y) = x * 100 + y
            end do
        end do
    end subroutine filltab

    subroutine printtab()
        integer :: x, y

        do x = 1, dimx
            write(*, '(I3, 2X, 6F8.1)') x, (ftab(x, y), y = 1, dimy)
        end do
    end subroutine printtab
end module arrayOps

program test
    use arrayOps
    implicit none

    call filltab()
    call printtab()
end program test