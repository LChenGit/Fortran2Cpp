module zflmconj_module
    implicit none
contains
    subroutine zflmconj(lmax, zflm1, zflm2)
        integer, intent(in) :: lmax
        complex(8), intent(in) :: zflm1(*)
        complex(8), intent(out) :: zflm2(*)
        integer :: l,m,lm1,lm2
        complex(8) :: z1
        
        do l=0,lmax
            lm1=l**2
            lm2=(l+1)**2
            do m=-l,-1
                lm1=lm1+1
                lm2=lm2-1
                z1=zflm1(lm1)
                zflm2(lm1)=conjg(zflm1(lm2))
                zflm2(lm2)=conjg(z1)
                if (mod(m,2).ne.0) then
                    zflm2(lm1)=-zflm2(lm1)
                    zflm2(lm2)=-zflm2(lm2)
                end if
            end do
            if (l /= 0) then
                lm1=lm1+1
                zflm2(lm1)=conjg(zflm1(lm1))
            end if
        end do
    end subroutine zflmconj
end module zflmconj_module