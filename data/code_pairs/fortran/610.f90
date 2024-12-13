module inversionGrid
  implicit none
  save

  type :: inversion_grid
    logical :: is_initialized = .false.
  end type inversion_grid
end module inversionGrid

module errorMessage
  implicit none
  save

  type :: error_message
    logical :: has_error = .false.
  end type error_message
end module errorMessage

module create_shore_lines_f2pyVar
  use inversionGrid
  use errorMessage
  implicit none
  save

  type (inversion_grid) :: invgrid
  type (error_message) :: errmsg
  logical :: invgrid_created = .false.
end module create_shore_lines_f2pyVar

program test
  use create_shore_lines_f2pyVar
  implicit none

  ! Assuming direct manipulation of members for testing purposes
  invgrid%is_initialized = .true.
  errmsg%has_error = .true.

  if (.not. invgrid_created) then
    print *, "invgrid_created is initially .false."
  else
    print *, "invgrid_created is not .false. (Error)"
  endif

  if (invgrid%is_initialized) then
    print *, "invgrid is initialized."
  else
    print *, "invgrid is not initialized. (Error)"
  endif

  if (errmsg%has_error) then
    print *, "errmsg has an error."
  else
    print *, "errmsg does not have an error. (Error)"
  endif
end program test