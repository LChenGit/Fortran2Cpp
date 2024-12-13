module constants_module
    implicit none
    double precision, parameter :: pi = 3.141592653589793238462d0
    double precision, parameter :: dr = 0.05d0, rmax = 100d0, rasymp = 50d0
    integer, parameter :: nr = int(rmax / dr + 0.5d0), nasymp = int(rasymp / dr + 0.5d0)
    double precision, parameter :: ecmin = 0.002d0
    double precision :: vclus = 0.2d0, fluc = 0.1d0, rpot = 15d0
    integer :: num_para = -1
end module constants_module

program test_constants
    use constants_module
    ! Test cases
    print *, "Testing constants and variables..."
    print *, "pi: ", pi
    print *, "dr: ", dr
    print *, "rmax: ", rmax
    print *, "rasymp: ", rasymp
    print *, "nr: ", nr
    print *, "nasymp: ", nasymp
    print *, "ecmin: ", ecmin
    print *, "vclus: ", vclus
    print *, "fluc: ", fluc
    print *, "rpot: ", rpot
    print *, "num_para: ", num_para
end program test_constants