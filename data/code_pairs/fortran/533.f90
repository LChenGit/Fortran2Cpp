module iotk_xtox_interf
  implicit none

contains

  subroutine iotk_read_int(file_handle, data)
    integer, intent(in) :: file_handle
    integer, intent(out) :: data
    ! Dummy implementation for testing
    data = 42
  end subroutine iotk_read_int

  subroutine iotk_read_float(file_handle, data)
    integer, intent(in) :: file_handle
    real, intent(out) :: data
    ! Dummy implementation for testing
    data = 3.14
  end subroutine iotk_read_float

end module iotk_xtox_interf