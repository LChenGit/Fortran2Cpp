module SMConstants
    implicit none
    private
    public :: DOUBLE_DIGITS, SINGLE_DIGITS, RP, SP, CP

    integer, parameter :: DOUBLE_DIGITS = 15
    integer, parameter :: SINGLE_DIGITS = 6
    integer, parameter :: RP = selected_real_kind(DOUBLE_DIGITS)
    integer, parameter :: SP = selected_real_kind(SINGLE_DIGITS)
    integer, parameter :: CP = selected_real_kind(DOUBLE_DIGITS)
end module SMConstants

program testSMConstants
    use SMConstants
    implicit none

    real(RP) :: rpVar = 1.0_RP
    real(SP) :: spVar = 1.0_SP
    real(CP) :: cpVar = 1.0_CP

    if (DOUBLE_DIGITS /= 15) then
        print *, "Test for DOUBLE_DIGITS failed."
    else
        print *, "Test for DOUBLE_DIGITS passed."
    endif

    if (SINGLE_DIGITS /= 6) then
        print *, "Test for SINGLE_DIGITS failed."
    else
        print *, "Test for SINGLE_DIGITS passed."
    endif

    print *, "Kind tests passed if no compilation errors occur."
end program testSMConstants