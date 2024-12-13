module timing_module
  implicit none

contains
  function MPI_wtime()
    implicit none
    double precision :: MPI_wtime
    integer :: time, rate, dummy

    call system_clock( time, rate, dummy )
    MPI_wtime = dble(time) / dble(rate)
  end function MPI_wtime
end module timing_module