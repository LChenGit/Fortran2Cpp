module scf_data
  implicit none
  integer, parameter :: dimX=10, dimY=10, dimZ=10, num_rho_stock=2
  real :: rho(dimX, dimY, dimZ)
  real :: rho_in(dimX, dimY, dimZ, num_rho_stock+1)
  real :: rho_s(dimX, dimY, dimZ, 2)
  real :: rho_s_in(dimX, dimY, dimZ, 2, num_rho_stock+1)
  real :: rho_out(dimX, dimY, dimZ, num_rho_stock)
  real :: rho_s_out(dimX, dimY, dimZ, 2, num_rho_stock)
  integer :: Miter
  integer :: ilsda
contains
  subroutine copy_density
    integer :: iiter, is
    
    if (Miter == 1) then
      rho_in(:,:,:,num_rho_stock+1) = rho(:,:,:)
      if (ilsda == 1) then
        rho_s_in(:,:,:,1:2,num_rho_stock+1) = rho_s(:,:,:,1:2)
      end if
    end if

    do iiter=1,num_rho_stock
      rho_in(:,:,:,iiter) = rho_in(:,:,:,iiter+1)
    end do
    do iiter=1,num_rho_stock-1
      rho_out(:,:,:,iiter) = rho_out(:,:,:,iiter+1)
    end do

    if (ilsda == 1) then
      do iiter=1,num_rho_stock
        do is=1,2
          rho_s_in(:,:,:,is,iiter) = rho_s_in(:,:,:,is,iiter+1)
        end do
      end do
      do iiter=1,num_rho_stock-1
        do is=1,2
          rho_s_out(:,:,:,is,iiter) = rho_s_out(:,:,:,is,iiter+1)
        end do
      end do
    end if
  end subroutine copy_density
end module scf_data

program test
  use scf_data
  implicit none
  
  Miter = 1
  ilsda = 1
  call copy_density
end program test