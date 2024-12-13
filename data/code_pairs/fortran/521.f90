module modphonon
    implicit none
    integer :: nbph = 0
    real(8), allocatable :: vqlwrt(:,:)

contains

    subroutine increase_nbph()
        nbph = nbph + 1
    end subroutine increase_nbph

end module modphonon