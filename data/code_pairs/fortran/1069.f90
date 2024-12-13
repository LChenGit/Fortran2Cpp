module precision
    integer, parameter :: double = selected_real_kind(15, 307)
end module precision

module fittingmod
    use precision, only: double
    implicit none
    integer, pointer :: ntrace2, nfit2, ilinkpsf2, nline2
    integer, dimension(:), pointer :: isol2
    real(double), dimension(:), pointer :: line2, sol2
end module fittingmod