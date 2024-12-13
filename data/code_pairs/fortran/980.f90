program main
    call warn('Test warn message')
    call tnoua('TestTnoua', 8)
    call dasign(1, -1, 'example.txt', 100)
    ! call vexit(0) ! This will stop the program; uncomment to test
end program main

subroutine warn(msg)
    character(*), intent(in) :: msg
    print '(A)', ' ' // trim(msg)
end subroutine warn

subroutine tnoua(ia, nc)
    character(*), intent(in) :: ia
    integer, intent(in) :: nc
    print '(A$)', ia(1:nc)
end subroutine tnoua

subroutine dasign(lu, mode, ia, len)
    integer, intent(in) :: lu, mode, len
    character(*), intent(in) :: ia
    ! Placeholder for actual file operation logic
    print *, 'dasign called with lu=', lu, ', mode=', mode, ', ia=', ia, ', len=', len
end subroutine dasign

subroutine vexit(ierr)
    integer, intent(in) :: ierr
    if (ierr /= 0) print *, 'exit called with error code', ierr
    stop
end subroutine vexit