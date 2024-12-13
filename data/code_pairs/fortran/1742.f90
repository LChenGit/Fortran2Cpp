module MOD_EXTURAY
contains
    subroutine extUray(U, Uray, nd, np, iray)
        implicit none
        real*8, intent(in) :: U(:,:)
        real*8, intent(out) :: Uray(:)
        integer, intent(in) :: nd, np, iray
        integer :: L
        
        do L = 1, nd
            Uray(L) = U(L, iray)
        end do
    end subroutine extUray
end module MOD_EXTURAY