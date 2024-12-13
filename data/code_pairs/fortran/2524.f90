module clock_plugin_mod
    implicit none
contains
    subroutine plugin_clock()
        print *, 'Fortran Stdout: plugin_clock subroutine executed successfully.'
    end subroutine plugin_clock
end module clock_plugin_mod