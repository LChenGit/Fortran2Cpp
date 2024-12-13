module recoverC_mod
    implicit none
    contains

    subroutine recoverC (n1, n2, hlist, dhlist, hbox, dhbox)
        integer, intent (in) :: n1, n2
        real, intent(in) :: hlist(*), dhlist(*)
        real, intent(out) :: hbox(n1, n2), dhbox(n1, n2)
        integer :: index, indexcoulomb, ii, kk

        ii = 1
        kk = 0

        indexcoulomb = n1*n2
        do index = 1, indexcoulomb
            kk = kk + 1
            hbox(ii,kk) = hlist(index)
            dhbox(ii,kk) = dhlist(index)
            if (mod(index,n2) == 0) then
                ii = ii + 1
                kk = kk - n2
            end if
        end do
    end subroutine recoverC
end module recoverC_mod