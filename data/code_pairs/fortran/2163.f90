! m_comm_data_IO.f90
module m_comm_data_IO
    use iso_fortran_env, only: int64
    implicit none
    integer(int64) :: num_neib_domain_IO = 0
end module m_comm_data_IO

! t_comm_table.f90
module t_comm_table
    use iso_fortran_env, only: int64
    implicit none

    type communication_table
        integer(int64) :: num_neib = 0
    end type communication_table
end module t_comm_table

! set_comm_table_4_IO.f90
module set_comm_table_4_IO
    use iso_fortran_env, only: int64
    use t_comm_table, only: communication_table
    use m_comm_data_IO, only: num_neib_domain_IO
    implicit none

contains

    subroutine copy_comm_tbl_type_from_IO(comm_tbls)
        type(communication_table), intent(inout) :: comm_tbls
        comm_tbls%num_neib = num_neib_domain_IO
    end subroutine copy_comm_tbl_type_from_IO
end module set_comm_table_4_IO

! test_comm_table.f90 - Test Program
program test_comm_table
    use set_comm_table_4_IO
    use m_comm_data_IO, only: num_neib_domain_IO
    implicit none

    type(communication_table) :: comm_tbl

    ! Initialize with some test data
    num_neib_domain_IO = 2

    ! Call the subroutine
    call copy_comm_tbl_type_from_IO(comm_tbl)

    ! Verify the results
    print *, "Fortran Test Output:"
    print *, "num_neib =", comm_tbl%num_neib
end program test_comm_table