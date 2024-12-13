module lgemmx_module
contains
    subroutine LGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)
        integer :: m, n, k, inc1a, inc2a, inc1b, inc2b, inc1c, inc2c
        logical*8 :: alpha, beta
        logical*8, dimension(*) :: a, b, c
        integer :: i

        do i = 1, m
            c(i) = a(i) .AND. b(i)
        end do
    end subroutine LGEMMX
end module lgemmx_module