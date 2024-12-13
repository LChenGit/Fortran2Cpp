module correction_module
  implicit none
  contains
    subroutine correctflux(nef,ipnei,neifa,neiel,flux,vfa,advfa,area,vel,alet,ielfa,ale,ifabou,nefa,nefb,xxnj,gradpcfa)
      implicit none
      integer, intent(in) :: nef,ipnei(*),neifa(*),neiel(*),ielfa(4,*),ifabou(*),nefa,nefb
      real(8), intent(in) :: vfa(0:7,*),advfa(*),area(*),vel(nef,0:7),alet(*),ale(*),xxnj(3,*),gradpcfa(3,*)
      real(8), intent(inout) :: flux(*)
      integer :: i, indexf, ifa, iel, indexb

      do i=nefa,nefb
        do indexf=ipnei(i)+1,ipnei(i+1)
          ifa=neifa(indexf)
          iel=neiel(indexf)
          if(iel > 0) then
            flux(indexf)=flux(indexf)+vfa(5,ifa)*advfa(ifa)* &
            ((vel(i,4)-vel(iel,4))*alet(indexf)-(gradpcfa(1,ifa)*xxnj(1,indexf) &
            +gradpcfa(2,ifa)*xxnj(2,indexf)+gradpcfa(3,ifa)*xxnj(3,indexf)))
          else
            indexb=-ielfa(2,ifa)
            if(indexb > 0) then
              if(((ifabou(indexb+1) == 0) .or. (ifabou(indexb+2) == 0) .or. (ifabou(indexb+3) == 0)) .and. &
              (ifabou(indexb+4) /= 0)) then
                flux(indexf)=flux(indexf)+vfa(5,ifa)*advfa(ifa)*(vel(i,4)*ale(indexf) &
                -(gradpcfa(1,ifa)*xxnj(1,indexf)+gradpcfa(2,ifa)*xxnj(2,indexf) &
                +gradpcfa(3,ifa)*xxnj(3,indexf)))
              end if
            end if
          end if
        end do
      end do
    end subroutine correctflux
end module correction_module