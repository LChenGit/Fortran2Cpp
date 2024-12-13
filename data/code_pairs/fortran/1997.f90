! main_subr.f90
subroutine subr(a)
    implicit none
    real, intent(inout) :: a(50)
    a = 0
end subroutine subr