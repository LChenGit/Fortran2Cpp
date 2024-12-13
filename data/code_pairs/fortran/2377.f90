module performance
  implicit none
contains
  subroutine perf_header()
    write(*,*)
    write(*,'("        # Photons    CPU time (sec)    Photons/sec  ")')
    write(*,'("      ----------------------------------------------")')
  end subroutine perf_header

  subroutine perf_footer()
    write(*,'("      ----------------------------------------------")')
    write(*,*)
  end subroutine perf_footer

  subroutine perf_numbers(count, time)
    integer, intent(in) :: count
    real, intent(in) :: time
    if(time <= 0.0) then
      write(*,'(1X,A,I12,3X,F10.1,2X,A)') " ", count, " ", time, "   ...   "
    else
      write(*,'(1X,A,I12,3X,F10.1,2X,F9.2)') " ", count, " ", time, real(count)/time
    end if
  end subroutine perf_numbers
end module performance

! Test Program
program test_performance
  use performance
  call perf_header()
  call perf_numbers(1000000, 123.4)
  call perf_numbers(500000, 0.0)
  call perf_footer()
end program test_performance