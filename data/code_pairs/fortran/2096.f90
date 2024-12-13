subroutine writesta(istep, j, icutb, l, ttime, time, dtime)
    implicit none

    integer istep, j, icutb, l
    real*8 ttime, time, dtime

    write(8,100) istep, j, icutb+1, l, ttime+time, time, dtime
    flush(8)

100 format(1x,i5,1x,i10,2(1x,i5),3(1x,e13.6))

end subroutine writesta