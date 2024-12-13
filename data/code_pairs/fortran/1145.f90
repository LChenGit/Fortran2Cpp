! plugin_clock.f90
subroutine plugin_clock()
    implicit none
    write(*,*) 'Clock plugin activated'
end subroutine plugin_clock

program test_plugin_clock
    call plugin_clock
end program test_plugin_clock