module netcdf_mod
  implicit none
contains
  subroutine open_file(filename)
    character(len=*), intent(in) :: filename
    print *, 'Opening file: ', trim(filename)
  end subroutine open_file

  function get_dimension(dimName) result(dim)
    character(len=*), intent(in) :: dimName
    integer :: dim
    dim = 10  ! Example dimension
  end function get_dimension
end module netcdf_mod