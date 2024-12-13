! count_w_lp2.f90
subroutine COUNT_W_LP2(result, source, dim, rext, sext, blkcnt, npes, hi, low, lmext, dist_cnt)
    implicit none
    integer, intent(in) :: dim, rext, sext(*), blkcnt, npes, lmext, dist_cnt
    integer, dimension(rext), intent(out) :: result
    logical, dimension(sext(1),sext(2)), intent(in) :: source
    integer, dimension(blkcnt), intent(in) :: hi, low
    integer :: i

    do i = 1, rext
        result(i) = 0
    end do
end subroutine COUNT_W_LP2