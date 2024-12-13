module control_bunch_input
    implicit none
    integer :: input_parameter = 10
    real(8) :: input_value = 25.5

contains

    subroutine set_input_parameter(value)
        integer, intent(in) :: value
        input_parameter = value
    end subroutine set_input_parameter

    function get_input_value() result(value)
        real(8) :: value
        value = input_value
    end function get_input_value

end module control_bunch_input