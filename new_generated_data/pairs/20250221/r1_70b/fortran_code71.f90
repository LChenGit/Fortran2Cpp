module my_module
    private
    integer :: some_variable = 0
    
    public :: get_value, set_value
contains
    function get_value() result(value)
        integer :: value
        value = some_variable
    end function get_value
    
    subroutine set_value(new_value)
        integer, intent(in) :: new_value
        some_variable = new_value
    end subroutine set_value
end module my_module

program main_program
    use my_module
    print *, "Initial value: ", get_value()
    call set_value(10)
    print *, "Value after setting: ", get_value()
end program main_program