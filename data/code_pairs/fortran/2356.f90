! File: CRASH_ModCaltz.f90
module CRASH_ModCaltz
contains
    function get_value() result(val)
        integer :: val
        val = 42
    end function get_value
end module CRASH_ModCaltz

! File: test_CRASH_ModCaltz.f90
program testCRASH_ModCaltz
    use CRASH_ModCaltz
    implicit none
    
    integer :: value
    
    value = get_value()
    print *, 'Value from CRASH_ModCaltz:', value
end program testCRASH_ModCaltz