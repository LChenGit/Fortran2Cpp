! Main code
subroutine copyFirstElement(wbuf1, wbuf2)
    character(len=2), intent(out) :: wbuf1
    character(len=2), dimension(:), intent(in) :: wbuf2
    wbuf1 = wbuf2(1)
end subroutine copyFirstElement