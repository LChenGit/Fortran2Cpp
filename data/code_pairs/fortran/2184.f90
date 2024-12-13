subroutine SSMV(N, X, Y, NELT, IA, JA, A, ISYM)
    implicit none
    integer, intent(in) :: N, NELT, ISYM
    real, dimension(N), intent(in) :: X
    real, dimension(NELT), intent(in) :: A
    integer, dimension(NELT), intent(in) :: IA
    integer, dimension(N+1), intent(in) :: JA
    real, dimension(N), intent(out) :: Y
    integer :: I, J

    ! Initialize Y
    do I = 1, N
        Y(I) = 0.0
    end do

    ! Sparse matrix-vector multiplication
    do I = 1, NELT
        Y(IA(I)) = Y(IA(I)) + A(I) * X(JA(I))
    end do

    if (ISYM == 1) then
        do I = 1, NELT
            Y(JA(I)) = Y(JA(I)) + A(I) * X(IA(I))
        end do
    endif
end subroutine SSMV