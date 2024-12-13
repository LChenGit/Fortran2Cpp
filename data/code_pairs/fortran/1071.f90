module mod_xghis1
    implicit none
    integer, parameter :: nelemg = 100
    real :: xargat(nelemg)
contains
    subroutine xghis1(a, ln, nft, nlt)
        integer, intent(in) :: ln, nft, nlt
        real, dimension(ln, *) :: a
        integer :: i

        do i = nft, nlt
            xargat(i) = a(1,i)
        end do
    end subroutine xghis1
end module mod_xghis1