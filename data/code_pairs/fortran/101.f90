module m_work_4_sph_trans_spin

  implicit none
  double precision, allocatable :: vr_rtm_wk(:), sp_rlm_wk(:)

  integer, parameter :: kreal = selected_real_kind(p=8)
  integer, parameter :: kint = selected_int_kind(8)
  integer, parameter :: nnod_rlm = 10, nnod_rtm = 20

contains

  subroutine allocate_work_sph_trans(ncomp)
    integer(kind = kint), intent(in) :: ncomp

    allocate(sp_rlm_wk(nnod_rlm * ncomp))
    allocate(vr_rtm_wk(nnod_rtm * ncomp))

    call clear_bwd_legendre_work(ncomp)
    call clear_fwd_legendre_work(ncomp)
  end subroutine allocate_work_sph_trans

  subroutine deallocate_work_sph_trans
    deallocate(vr_rtm_wk, sp_rlm_wk)
  end subroutine deallocate_work_sph_trans

  subroutine clear_fwd_legendre_work(ncomp)
    integer(kind = kint), intent(in) :: ncomp
    if (ncomp <= 0) return
    sp_rlm_wk(1:nnod_rlm * ncomp) = 0.0d0
  end subroutine clear_fwd_legendre_work

  subroutine clear_bwd_legendre_work(ncomp)
    integer(kind = kint), intent(in) :: ncomp
    if (ncomp <= 0) return
    vr_rtm_wk(1:nnod_rtm * ncomp) = 0.0d0
  end subroutine clear_bwd_legendre_work

end module m_work_4_sph_trans_spin