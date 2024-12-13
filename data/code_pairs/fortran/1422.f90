module kind_types
  implicit none
  integer, parameter :: dp = selected_real_kind(15)
  integer, parameter :: qp = selected_real_kind(33)
  complex(dp), parameter :: cI_dp = (0._dp, 1._dp)
  complex(qp), parameter :: cI_qp = (0._qp, 1._qp)

contains

  function cmplx_dp(re, im)
    real(dp), intent(in) :: re
    real(dp), intent(in), optional :: im
    complex(dp) :: cmplx_dp
    if (present(im)) then
      cmplx_dp = complex(re, im)
    else
      cmplx_dp = complex(re, 0._dp)
    endif
  end function cmplx_dp

  function cmplx_qp(re, im)
    real(qp), intent(in) :: re
    real(qp), intent(in), optional :: im
    complex(qp) :: cmplx_qp
    if (present(im)) then
      cmplx_qp = complex(re, im)
    else
      cmplx_qp = complex(re, 0._qp)
    endif
  end function cmplx_qp

end module kind_types