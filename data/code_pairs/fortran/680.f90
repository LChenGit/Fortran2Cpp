subroutine COUNT_W_LP5(result, rext)
    implicit none
    integer, intent(in) :: rext(4)
    integer, dimension(rext(1),rext(2),rext(3),rext(4)), intent(out) :: result
    integer :: i, j, k, l

    ! Initialize result array to 0
    do l = 1, rext(4)
        do k = 1, rext(3)
            do j = 1, rext(2)
                do i = 1, rext(1)
                    result(i,j,k,l) = 0
                end do
            end do
        end do
    end do
end subroutine COUNT_W_LP5