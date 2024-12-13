module selci_mxmb_mod
    implicit none
contains
    subroutine selci_mxmb(a, mcola, mrowa, b, mcolb, mrowb, r, mcolr, mrowr, ncol, nlink, nrow)
        implicit none
        double precision, dimension(:), intent(in) :: a, b
        double precision, dimension(:), intent(inout) :: r
        integer, intent(in) :: mcola, mrowa, mcolb, mrowb, mcolr, mrowr, ncol, nlink, nrow
        integer :: ir, ib, ibb, ia, irr, iaa, i, j, k
        double precision :: fac

        ir = 1
        ib = 1
        do j = 1, nrow
            ibb = ib
            ia = 1
            do k = 1, nlink
                fac = b(ibb)
                if (fac /= 0.0d0) then
                    irr = ir
                    iaa = ia
                    do i = 1, ncol
                        r(irr) = r(irr) + fac * a(iaa)
                        irr = irr + mcolr
                        iaa = iaa + mcola
                    end do
                end if
                ibb = ibb + mcolb
                ia = ia + mrowa
            end do
            ir = ir + mrowr
            ib = ib + mrowb
        end do
    end subroutine selci_mxmb
end module selci_mxmb_mod