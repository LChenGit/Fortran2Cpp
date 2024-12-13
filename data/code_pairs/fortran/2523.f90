! Filename: test_module.f90
module test_module
    implicit none
contains

    subroutine cuconmut_dz(data, size)
        double precision, intent(inout) :: data(:)
        integer, intent(in) :: size
        integer :: i
        do i = 1, size
            data(i) = data(i) * 2.0
        end do
    end subroutine cuconmut_dz

    subroutine cuconmut_dc(data, size)
        double complex, intent(inout) :: data(:)
        integer, intent(in) :: size
        integer :: i
        do i = 1, size
            data(i) = data(i) * (2.0, 0.0)
        end do
    end subroutine cuconmut_dc

end module test_module

program test_cuconmut
    use test_module
    implicit none

    double precision :: real_data(5)
    double complex :: complex_data(5)

    ! Initialize real_data
    real_data = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    call cuconmut_dz(real_data, 5)
    print *, 'Real data after cuconmut: ', real_data

    ! Initialize complex_data
    complex_data = (/ (1.0, 1.0), (2.0, 2.0), (3.0, 3.0), (4.0, 4.0), (5.0, 5.0) /)
    call cuconmut_dc(complex_data, 5)
    print *, 'Complex data after cuconmut: ', complex_data

end program test_cuconmut