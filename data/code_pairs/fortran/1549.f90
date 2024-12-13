module MOD_COMPRO
    contains
    subroutine COMPRO (PROFILE,EMINT,NFOBR,W,JFIRST,JLAST)
    implicit none
    real*8, intent(inout) :: PROFILE(:)
    real*8, intent(in) :: EMINT(:)
    real*8, intent(in) :: W
    integer, intent(in) :: NFOBR, JFIRST, JLAST
    integer :: K

    do K = 1, NFOBR
        if (JFIRST .EQ. JLAST) then
            PROFILE(K)=EMINT(K)
        else
            PROFILE(K)=PROFILE(K)+W*EMINT(K)
        endif
    enddo

    end subroutine COMPRO
end module MOD_COMPRO