module drivermod_serial
  implicit none
contains
  function driver() result(success)
    logical :: success
    ! Assuming driver does something simple for the test
    success = .true.
  end function driver
end module drivermod_serial