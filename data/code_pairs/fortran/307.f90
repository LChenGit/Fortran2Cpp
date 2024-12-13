! Main operation - assumed to be part of a larger program or module
subroutine updateY(Y, TILTS, TILTC, EKK, I)
    implicit none
    double precision, intent(inout) :: Y(2)
    double precision, intent(in) :: TILTS(*), TILTC(*)
    double precision, intent(in) :: EKK
    integer, intent(in) :: I

    Y(1) = Y(1) - EKK * TILTS(I)
    Y(2) = Y(2) + EKK * TILTC(I)
end subroutine updateY