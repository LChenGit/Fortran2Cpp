subroutine reinit2(kontet, ifac, ieln, netet_, newsize, ifatet, itetfa, iedg, ieled)
    implicit none

    integer, intent(inout) :: kontet(4,*), ifac(4,*), ieln(2,*), netet_, newsize
    integer, intent(inout) :: ifatet(4,*), itetfa(2,*), iedg(3,*), ieled(2,*)
    integer :: i, j

    kontet(4, netet_) = netet_ + 1
    do i = netet_ + 1, newsize
        do j = 1, 3
            kontet(j, i) = 0
        end do
        kontet(4, i) = i + 1
    end do
    kontet(4, newsize) = 0

    ! Initialization routines for ifac, ieln, ifatet, itetfa, iedg, ieled are omitted for brevity
end subroutine reinit2