module distance_module
    implicit none
contains
    subroutine distance_point_line_2D(P0, P1_line, P2_line, dis, normal)
        implicit none
        double precision, intent(IN) :: P0(2), P1_line(2), P2_line(2)
        double precision, intent(OUT) :: dis
        double precision, intent(OUT) :: normal(2)
        double precision :: a, b, c
        a = (P2_line(2) - P1_line(2))
        b = -(P2_line(1) - P1_line(1))
        c = -(a * P1_line(1) + b * P1_line(2))
        normal(1) = a / dsqrt(a**2 + b**2)
        normal(2) = b / dsqrt(a**2 + b**2)
        dis = (a * P0(1) + b * P0(2) + c) / dsqrt(a**2 + b**2)
    end subroutine distance_point_line_2D
end module distance_module