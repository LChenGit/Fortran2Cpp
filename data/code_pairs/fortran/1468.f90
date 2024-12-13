program tryreshape
  implicit none
  integer, allocatable :: vect1(:), resh1(:,:)
  integer, pointer :: vect(:), resh(:,:)
  integer :: vect2(2*4), resh2(2,4)
  integer :: r, nb

  r = 2
  nb = 4

  allocate(vect(nb*r),vect1(nb*r))
  allocate(resh(r,nb),resh1(r,nb))

  vect = 1
  vect1 = 1
  vect2 = 1

  resh2 = reshape(vect2, (/r,nb/))
  resh1 = reshape(vect1, (/r,nb/))
  resh = reshape(vect, (/r,nb/))
end program tryreshape