module linkedcells
  implicit none
  integer :: nboxesx, nboxesy, nboxesz
  double precision :: xmin, ymin, zmin, xmax, ymax, zmax
  integer, allocatable :: ifirstbox(:,:,:), inextbox(:)
end module linkedcells