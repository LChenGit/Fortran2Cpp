module calc_module
  implicit none
contains
  subroutine calcpel(ne, vel, b, nef)
    implicit none
    integer :: ne, nef
    real(8) :: vel(ne, 0:5), b(ne)
    integer :: i
    do i = 1, ne
       vel(i, 4) = vel(i, 4) + b(i)
    enddo
  end subroutine calcpel
end module calc_module