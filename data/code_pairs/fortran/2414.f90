! original_program.f90
program t
    implicit none
    character(len=11) :: a, b, c, x, y, z
    character(len=11) :: form = 'unformatted'
    open (unit=56, status='new', file='tmpfile', access='sequential', form=form)
    inquire (unit=56, access=a, sequential=b, direct=c, form=x, formatted=y, unformatted=z)

    print *, a
    print *, b
    print *, c
    print *, x
    print *, y
    print *, z

    close (unit=56, status='delete')
end program t