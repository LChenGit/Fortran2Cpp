subroutine radresult(ntr,xloadact,bcr,nloadtr,tarea,tenv,physcon,erad,auview,fenv,irowrad,jqrad,nzsrad,q)
  implicit none

  integer i,j,k,ntr,nloadtr(*),irowrad(*),jqrad(*),nzsrad
  real*8 xloadact(2,*), tarea(*),tenv(*),auview(*),erad(*),fenv(*),physcon(*),bcr(ntr),q(*)

  do i=1,ntr
     q(i)=bcr(i)
  enddo

  do i=1,ntr
     do j=jqrad(i),jqrad(i+1)-1
        k=irowrad(j)
        q(k)=q(k)-auview(j)*bcr(i)
        q(i)=q(i)-auview(nzsrad+j)*bcr(k)
     enddo
  enddo

  do i=1,ntr
     j=nloadtr(i)
     q(i)=q(i)-fenv(i)*physcon(2)*tenv(i)**4
     xloadact(2,j)=max(tarea(i)**4-q(i)/(erad(i)*physcon(2)),0.d0)
     xloadact(2,j)=(xloadact(2,j))**0.25d0+physcon(1)
  enddo
end subroutine radresult