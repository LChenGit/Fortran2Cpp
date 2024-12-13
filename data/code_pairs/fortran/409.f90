subroutine mafillpbc(nef,au,ad,jq,irow,b,iatleastonepressurebc,nzs)
    implicit none
    integer, intent(in) :: nef, jq(*), irow(*), iatleastonepressurebc, nzs
    real(kind=8), intent(inout) :: ad(*), au(*), b(*)
    integer :: i
    
    if (iatleastonepressurebc.eq.0) then
        ad(nef) = 1.d0
        b(nef) = 0.d0
        do i=2,nef
            if (jq(i)-1>0) then
                if (irow(jq(i)-1).eq.nef) then
                    au(jq(i)-1) = 0.d0
                endif
            endif
        enddo
    endif
end subroutine mafillpbc