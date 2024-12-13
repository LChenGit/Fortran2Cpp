subroutine adjust(km, nl, Cpd, Ps, PH, P, T, Th, kap)
  implicit none
  integer km,nl,jn,i,j,k,jc
  real, dimension(km) :: Th, T, P, TOLD
  real, dimension(km+1) :: PH
  real Cpd, Ps, kap, sum, thbar, ahm, a2, RDCP, X
  integer :: k
  
  do k=1,km
     TOLD(k)=0.
  end do
  
  RDCP = kap
  
  jc=0
  do i=nl-1,1,-1
     jn=0
     sum=Th(i)
     do j=i+1,nl
        sum=sum+Th(j)
        thbar=sum/real(j-i+1)
        if (Th(j) < thbar) then
          jn=j
        end if
     end do
     if (jn == 0) then
        cycle
     end if
     
     ahm=0.0
     do j=i,jn
        ahm= ahm + Cpd * T(j) * ( PH(j) - PH(j+1) )
     end do
     
     a2=0.0
     do j=i,jn
        X=(P(j)/Ps)**RDCP
        TOLD(j)=T(j)
        T(j)=X
        a2 = a2 + Cpd * X * ( PH(j) - PH(j+1) )
     end do
     
     do j=i,jn
        Th(j) = ahm / a2
        T(j) = TOLD(j) * Th(j)
     end do
     
     if (Th(jn+1) < Th(jn) .and. jn < nl) then
        jn = jn + 1
        goto 12
     end if
12   continue
  end do
end subroutine adjust