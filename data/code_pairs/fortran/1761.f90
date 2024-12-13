! main.f90
program main
    implicit none
    double precision, parameter :: rad = 3.14159265358979323846 / 180.0
    double precision :: pbias
    double precision :: input_angle

    input_angle = 45.0
    call update_pbias(input_angle, pbias)
    print *, 'Updated pbias:', pbias
end program main

subroutine update_pbias(input_angle, pbias)
    double precision, intent(in) :: input_angle
    double precision, intent(out) :: pbias
    double precision, parameter :: rad = 3.14159265358979323846 / 180.0
    
    pbias = cos(input_angle * rad) ** 0.576
end subroutine update_pbias