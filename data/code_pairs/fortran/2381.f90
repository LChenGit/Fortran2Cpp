subroutine gapcon(ak,d,flowm,temp,predef,time,ciname,slname,msname,coords,noel,node,npred,kstep,kinc,area)
    implicit none
    character(len=80) :: ciname, slname, msname
    integer :: noel, node, npred, kstep, kinc
    real(8) :: ak(5), d(2), flowm(2), temp(2), predef(2,*), time(*), coords(3), area
    ! The subroutine body does nothing in this example
    return
end subroutine gapcon