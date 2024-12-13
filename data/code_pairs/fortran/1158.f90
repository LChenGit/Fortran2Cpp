module iotk_fmt_interf
implicit none
private

public :: iotk_basefmt_x, iotk_wfmt_x

contains

function iotk_basefmt_x(type, ikind, ilen) result(formatted_string)
  character(len=*), intent(in) :: type
  integer, intent(in) :: ikind, ilen
  character(len=100) :: formatted_string
  
  write(formatted_string, '(A, I0, A, I0)') trim(type), ikind, " Length: ", ilen
end function iotk_basefmt_x

function iotk_wfmt_x(type, ikind, isize, ilen, sep) result(formatted_string)
  character(len=*), intent(in) :: type
  integer, intent(in) :: ikind, isize, ilen
  character(len=*) :: sep
  character(len=150) :: formatted_string
  
  write(formatted_string, '(A, I0, A, I0, A, A)') trim(type), ikind, " Size: ", isize, " Length: ", ilen, sep
end function iotk_wfmt_x

end module iotk_fmt_interf