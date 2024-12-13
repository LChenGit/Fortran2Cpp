module netcdf_utilities
  implicit none
contains
  function openFile(filename) result(status)
    character(len=*), intent(in) :: filename
    integer :: status
    
    ! Mock implementation of opening a file and returning a status code
    ! 0 indicates success, non-zero indicates failure (simplified example)
    if (trim(filename) == 'example.nc') then
      status = 0
    else
      status = -1
    end if
  end function openFile
end module netcdf_utilities