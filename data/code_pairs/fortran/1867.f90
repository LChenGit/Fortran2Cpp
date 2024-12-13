module m_tenstr_rrlw_cld
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none
    save

    real(kind=real64) :: abscld1
    real(kind=real64), dimension(2) :: absice0
    real(kind=real64), dimension(2,5) :: absice1
    real(kind=real64), dimension(43,16) :: absice2
    real(kind=real64), dimension(46,16) :: absice3
    real(kind=real64) :: absliq0
    real(kind=real64), dimension(58,16) :: absliq1
end module m_tenstr_rrlw_cld