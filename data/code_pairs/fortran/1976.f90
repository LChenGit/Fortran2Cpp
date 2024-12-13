module constants
    implicit none
    integer, parameter :: RLEN = selected_real_kind(15, 307)
    real(kind=RLEN), parameter :: SEC_PER_DAY = 86400.0_RLEN
end module constants

module time_module
    use constants, only: RLEN
    implicit none
    real(kind=RLEN) :: timestep = 43200.0_RLEN
end module time_module

module delta_module
    use constants, only: RLEN, SEC_PER_DAY
    use time_module, only: timestep
    implicit none
contains
    function GetDelta() result(Delta)
       real(kind=RLEN) :: Delta
       Delta = timestep / SEC_PER_DAY
    end function GetDelta
end module delta_module