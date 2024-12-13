module global_variables
    implicit none
    integer, parameter :: Lsite = 5
    double precision, parameter :: t0 = 1.0d0
    double precision, allocatable :: Hmat_kin(:,:)
end module global_variables

subroutine PBME_allocation
    use global_variables
    implicit none
    integer :: i, j

    allocate(Hmat_kin(Lsite,Lsite))
    Hmat_kin = 0d0
    do i = 1, Lsite
        j = i + 1
        if(j > Lsite) j = 1
        Hmat_kin(i, j) = -t0
        j = i - 1
        if(j < 1) j = Lsite
        Hmat_kin(i, j) = -t0
    end do
end subroutine PBME_allocation

program test
    use global_variables
    call PBME_allocation
    
    ! Test
    if (all(Hmat_kin /= 0d0)) then
        print *, "Hmat_kin allocation and initialization test passed."
    else
        print *, "Hmat_kin allocation and initialization test failed."
    endif
end program test