module intcnt_module
    implicit none
contains
    integer function intCnt(int, list, llist)
        integer, intent(in) :: int
        integer, intent(in) :: list(*)
        integer, intent(in) :: llist
        integer :: i
        
        intCnt = 0
        do i = 1, llist
            if (list(i) == int) then
                intCnt = intCnt + 1
            end if
        end do
    end function intCnt
end module intcnt_module