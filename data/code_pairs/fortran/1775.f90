module Blade
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    real(real64), allocatable :: C(:)
    real(real64), allocatable :: DR(:)
    real(real64) :: R
    integer :: NB
end module Blade