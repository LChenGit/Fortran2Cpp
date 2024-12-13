subroutine writevector(ad, neq, number)
    implicit none
    character(len=12) :: name
    integer :: neq, i, number
    real(8) :: ad(*)

    name = 'vector_' // char(iachar('a') + number - 1) // '.out'

    open(10, file=name, status='unknown')
    write(10, *) 'vector number ', number
    do i = 1, neq
        write(10, *) 'row ', i, ' value ', ad(i)
    end do
    close(10)
end subroutine writevector