subroutine writeqnode(myid, qnode, qnodesize)
    implicit none
    integer :: i
    integer, intent(in) :: myid, qnodesize
    real*8, intent(in) :: qnode(qnodesize)
    character(len=20) :: filename

    write(filename, '(I4)') 1000+myid

    open(unit=1000+myid, file=trim(adjustl(filename)), status="replace", action="write")

    do i = 1, qnodesize
        write(1000+myid, '(1x, E14.8)') qnode(i)
    end do

    close(1000+myid)
end subroutine writeqnode