! mod_pdf.f90
module mod_pdf
  use, intrinsic :: iso_fortran_env, only: real64
  implicit none

  private
  public :: randn_box_muller, norm_pdf

contains

  subroutine randn_box_muller(x, mu, sigma)
    real(real64), intent(out) :: x
    real(real64), intent(in)  :: mu, sigma
    logical, save             :: have_second_sample = .false.
    real(real64), save        :: saved_sample
    real(real64)              :: myrand1, myrand2, v1, v2, rsq, fac

    if (.not. have_second_sample) then
      do
        call random_number(myrand1)
        call random_number(myrand2)
        v1 = 2.0_real64*myrand1 - 1.0_real64
        v2 = 2.0_real64*myrand2 - 1.0_real64
        rsq = v1*v1 + v2*v2
        if (rsq < 1.0_real64 .and. rsq /= 0.0_real64) exit
      end do

      fac = sqrt(-2.0_real64*log(rsq)/rsq)
      saved_sample = v1*fac*sigma + mu
      x = v2*fac*sigma + mu
      have_second_sample = .true.
    else
      x = saved_sample
      have_second_sample = .false.
    end if
  end subroutine randn_box_muller

  pure function norm_pdf(x, mean, variance) result(y)
    real(real64), intent(in) :: x, mean, variance
    real(real64)             :: y
    y = 1.0_real64 / (sqrt(variance * 2.0_real64 * 3.14159265358979323846_real64)) * exp( -(x - mean)**2 / (2.0_real64 * variance))
  end function norm_pdf

end module mod_pdf