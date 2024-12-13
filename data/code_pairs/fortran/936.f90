subroutine mysub(a, b, c, d)
    real(kind=8), intent(in) :: a, b
    real(kind=8), intent(out) :: c, d
    c = a + b
    d = a - b
end subroutine mysub