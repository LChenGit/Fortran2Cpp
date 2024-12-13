module constants
  implicit none
  ! Adjust the constant as per actual requirements
  integer, parameter :: MAX_STRING_LEN = 256
end module constants

subroutine create_name_database(prname, iproc, iregion_code, LOCAL_PATH)
  use constants, only: MAX_STRING_LEN
  implicit none
  integer :: iproc, iregion_code
  character(len=MAX_STRING_LEN) :: prname
  character(len=:) :: LOCAL_PATH
  character(len=MAX_STRING_LEN) :: procname
  write(procname, "('/proc',i6.6,'_reg',i1,'_')") iproc, iregion_code
  prname = trim(LOCAL_PATH) // trim(procname)
end subroutine create_name_database

subroutine create_name_database_adios(prname, iregion_code, LOCAL_PATH)
  use constants, only: MAX_STRING_LEN
  implicit none
  integer :: iregion_code
  character(len=MAX_STRING_LEN) :: prname
  character(len=:) :: LOCAL_PATH
  character(len=MAX_STRING_LEN) :: procname
  write(procname, "('/reg',i1,'_')") iregion_code
  prname = trim(LOCAL_PATH) // trim(procname)
end subroutine create_name_database_adios