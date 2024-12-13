! main.f90
program main
  implicit none
  real, dimension(3) :: vector3d
  real, dimension(3,3) :: matrix3d
  integer :: i, j

  vector3d(1) = 1.0
  vector3d(2) = 2.0
  vector3d(3) = 3.0
  matrix3d = 1.0

  ! Printing results for manual verification
  print *, 'Vector3d:'
  do i = 1, 3
     print *, vector3d(i)
  end do

  print *, 'Matrix3d:'
  do i = 1, 3
     do j = 1, 3
        print *, matrix3d(i, j)
     end do
  end do
end program main