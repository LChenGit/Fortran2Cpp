module dft_setting_params
    implicit none

    integer, parameter :: max_iter = 100
    real(kind=8), parameter :: conv_thresh = 1.0e-6
    logical :: print_info = .true.
#ifdef __LIBXC
    character(len=10) :: xc_functional = 'PBE'
#else
    character(len=10) :: xc_functional = 'LDA'
#endif

end module dft_setting_params