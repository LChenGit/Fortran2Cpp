! interpolate_bound_params.f90
subroutine interpolate_bound_params(nx, ny, pnx, pny, dx, dy, pbc_rhs, bc_rhs)
  implicit none
  integer, intent(in) :: nx, ny, pnx, pny
  double precision, intent(in) :: dx, dy
  double precision, dimension(pnx+pny,2), intent(in) :: pbc_rhs
  double precision, dimension(nx+ny,2), intent(out) :: bc_rhs

  integer :: ix, iy, pix, piy
  double precision :: x, y, px, py, pdx, pdy

  pdx = dx * dble(nx)/dble(pnx-1)
  pdy = dy * dble(ny)/dble(pny-1)

  bc_rhs = 0.0d0

  do ix = 1,nx
     x = (ix-0.5d0)*dx
     do pix = 1,pnx
        px = (pix-1d0)*pdx
        bc_rhs(ix,1) = bc_rhs(ix,1) + pbc_rhs(pix,1) * max(0d0,1d0-abs(px-x)/pdx)
        bc_rhs(ix,2) = bc_rhs(ix,2) + pbc_rhs(pix,2) * max(0d0,1d0-abs(px-x)/pdx)
     end do
  end do

  do iy = 1,ny
     y = (iy-0.5d0)*dy
     do piy = 1,pny
        py = (piy-1d0)*pdy
        bc_rhs(nx+iy,1) = bc_rhs(nx+iy,1) + pbc_rhs(pnx+piy,1) * max(0d0,1d0-abs(py-y)/pdy)
        bc_rhs(nx+iy,2) = bc_rhs(nx+iy,2) + pbc_rhs(pnx+piy,2) * max(0d0,1d0-abs(py-y)/pdy)
     end do
  end do
end subroutine interpolate_bound_params