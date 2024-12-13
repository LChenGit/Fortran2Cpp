module math_operations_mod
    implicit none
contains
    subroutine updateY(y, ed, ek, tiltc, tilts, crkve, cikve, one, dpda, ix, i)
        double precision, intent(inout) :: y(2)
        double precision, intent(in) :: ed(*), ek(*), tiltc(*), tilts(*)
        double precision, intent(in) :: crkve, cikve, one, dpda
        integer, intent(in) :: ix, i

        y(1) = y(1) + (ed(ix) * tiltc(i) * crkve - ek(ix) * tilts(i) * cikve) / (one + dpda)
        y(2) = y(2) + (ek(ix) * tiltc(i) * cikve + ed(ix) * tilts(i) * crkve) / (one + dpda)
    end subroutine updateY
end module math_operations_mod