module updat_mod
  implicit none
contains

  subroutine updat(u, udt, udtt, ui, neq, a6, a7, a8, a9, a10)
    implicit none
    integer, intent(in) :: neq
    real(8), intent(in) :: a6, a7, a8, a9, a10
    real(8), intent(inout) :: u(neq), udt(neq), udtt(neq), ui(neq)
    integer :: i
    real(8) :: udttld

    do i = 1, neq
      u(i) = u(i) + ui(i)
    end do

    do i = 1, neq
      udttld = udtt(i)
      udtt(i) = a6 * ui(i) + a7 * udt(i) + a8 * udttld
      udt(i) = udt(i) + a9 * udttld + a10 * udtt(i)
    end do
  end subroutine updat

end module updat_mod