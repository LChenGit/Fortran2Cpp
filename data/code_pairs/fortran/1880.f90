module mp_global
    contains
    subroutine mp_startup()
        print *, "MPI startup procedure called."
    end subroutine mp_startup
end module mp_global

module environment
    contains
    subroutine environment_start(code)
        character(len=*) :: code
        print *, "Environment start procedure called with code:", code
    end subroutine environment_start
end module environment

subroutine start_bse
    use mp_global,     only: mp_startup
    use environment,   only: environment_start
    implicit none
    character(len=9) :: code = 'BSE'
#ifdef __MPI
    call mp_startup()
#endif
    call environment_start(code)
end subroutine start_bse

program start_bse_program
    implicit none
    call start_bse
end program start_bse_program