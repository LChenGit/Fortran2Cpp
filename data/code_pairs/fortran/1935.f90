! Corrected Fortran subroutine with parameters for testing
subroutine s1(a, b, c, d, e, f)
    implicit none
    real, intent(inout) :: a, b, c, d
    integer, intent(inout) :: e, f
    save d
    equivalence(a, b), (b, c), (c, d)
    equivalence(e, f)
end subroutine s1