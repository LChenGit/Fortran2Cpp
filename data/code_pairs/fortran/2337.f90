module sire_functions
    implicit none
contains
    integer function sire_using_internal_blas()
        sire_using_internal_blas = 1
    end function sire_using_internal_blas

    integer function sire_using_internal_lapack()
        sire_using_internal_lapack = 1
    end function sire_using_internal_lapack

    integer function sire_using_internal_linpack()
        sire_using_internal_linpack = 1
    end function sire_using_internal_linpack
end module sire_functions