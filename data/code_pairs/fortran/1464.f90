module chanel_C 
    implicit none
    integer, parameter :: filename_len = 240

    integer ::       iw = 26
    integer, dimension(145) :: ifilen, ioda 
    character(len=filename_len) :: job_fn, output_fn, restart_fn, density_fn, log_fn, end_fn, ext_fn, archive_fn
    integer :: irecln = 1023, irecst 

end module chanel_C

program test_chanel_C
    use chanel_C
    implicit none

    print*, 'Testing module chanel_C'
    print*, 'iw = ', iw
end program test_chanel_C