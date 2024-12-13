module GribHandler
    implicit none
contains
    subroutine grib_index_get_int(key, value)
        character(*), intent(in) :: key
        integer, intent(out) :: value
        if (key == "intKey") then
            value = 42
        else
            value = -1
        endif
    end subroutine grib_index_get_int

    subroutine grib_index_get_string(key, value)
        character(*), intent(in) :: key
        character(*), intent(out) :: value
        if (key == "stringKey") then
            value = "TestString"
        else
            value = "Unknown"
        endif
    end subroutine grib_index_get_string
end module GribHandler

program testGribHandler
    use GribHandler
    implicit none
    integer :: intValue
    character(len=20) :: stringValue

    call grib_index_get_int("intKey", intValue)
    print *, "Test grib_index_get_int:", intValue

    call grib_index_get_string("stringKey", stringValue)
    print *, "Test grib_index_get_string:", trim(stringValue)
end program testGribHandler