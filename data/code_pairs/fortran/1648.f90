! Assuming the existence of relevant modules for MPI and file handling
subroutine stop_pp
  use io_files, only: iunwfc
  use mp, only: mp_end, mp_barrier
  use mp_global, only: mp_global_end
  use mp_world, only: world_comm
  implicit none

#ifdef __MPI
  logical :: op

  inquire(unit=iunwfc, opened=op)
  if (op) then
    close(unit=iunwfc, status='delete')
  endif

  call mp_barrier(world_comm)
  call mp_global_end()
#endif

  stop
end subroutine stop_pp