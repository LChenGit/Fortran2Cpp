module caps_module
  implicit none
contains
  subroutine caps(file_name)
    intrinsic Len, Index, AdjustL
    character(len=*), intent(inout) :: file_name
    character(len=Len(file_name)) :: temp_name
    character(len=26) :: low_case = "abcdefghijklmnopqrstuvwxyz", &
                         up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    integer :: ii, j

    temp_name = ""
    j = 0

    temp_name = file_name

    do ii = 1, Len(file_name)
      j = Index(up_case, file_name(ii:ii))
      if (j /= 0) temp_name(ii:ii) = low_case(j:j)
    end do

    temp_name = AdjustL(temp_name)
    file_name = temp_name
  end subroutine caps
end module caps_module