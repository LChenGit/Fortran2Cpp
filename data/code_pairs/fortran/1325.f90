! format_test.f90
program format_test
    implicit none
    integer :: intValue1 = 123, intValue2 = 4

    ! Test FORMAT (I12, i1)
    write(*, '(I12, i1)') intValue1, intValue2
end program format_test