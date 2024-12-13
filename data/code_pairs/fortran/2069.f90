module spec_min_module
  implicit none
contains
  double precision function spec_min(spec, nspec, nchannel, npnts)
    implicit none
    double precision, intent(in) :: spec(:,:,:)
    integer, intent(in) :: nspec, nchannel, npnts
    integer :: i

    spec_min = spec(nspec, nchannel, 1)
    do i = 2, npnts
       if (spec(nspec, nchannel, i) < spec_min) then
          spec_min = spec(nspec, nchannel, i)
       endif
    end do
  end function spec_min
end module spec_min_module