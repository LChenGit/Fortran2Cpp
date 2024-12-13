subroutine enq_v1_teldef(nae_max, nsp_max, nba_max, nch_max, s)
    integer, intent(inout) :: nae_max, nsp_max, nba_max, nch_max
    integer, intent(in) :: s

    ! Assuming these constants are defined inside the subroutine for simplicity
    integer, parameter :: max_aes = 100  ! Assumed value
    integer, parameter :: max_spac = 50  ! Assumed value

    if ( s /= 0 ) return

    nae_max = max_aes
    nsp_max = max_spac
    nba_max = 1
    nch_max = 1

end subroutine enq_v1_teldef