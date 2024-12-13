module ncdr_state
    implicit none
    integer :: current_ncdr_id = -1
    integer, dimension(:), allocatable :: ncdr_id_stack
    integer :: ncdr_id_stack_size = 0, ncdr_id_stack_count = 0
    logical :: init_done = .FALSE.
    character(len=200) :: cur_nc_file
    type ncdr_file
        integer :: dummy  ! Placeholder for actual ncdr_file content
    end type ncdr_file
    type(ncdr_file), dimension(:), allocatable :: ncdr_files
    integer :: ncdr_file_count = 0
    integer :: ncdr_file_total = 0
    integer :: ncdr_file_highest = 0
    integer, parameter :: NCDR_DEFAULT_ENT = 1024
    integer, parameter :: NCDR_CHUNKING = 16384
end module ncdr_state