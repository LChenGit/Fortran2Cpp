module modmain
    implicit none
    integer, parameter :: nstfv = 2, nspnfv = 2
    real(8), allocatable :: vkl(:,:)
contains
    subroutine putevalfv(fext, ik, evalfv)
        implicit none
        character(len=*), intent(in) :: fext
        integer, intent(in) :: ik
        real(8), intent(in) :: evalfv(nstfv,nspnfv)
        integer :: recl

        inquire(iolength=recl) vkl(:,ik), nstfv, nspnfv, evalfv
        !$OMP CRITICAL(u120)
        open(120, file='EVALFV'//trim(fext), form='UNFORMATTED', access='DIRECT', recl=recl)
        write(120, rec=ik) vkl(:,ik), nstfv, nspnfv, evalfv
        close(120)
        !$OMP END CRITICAL(u120)
    end subroutine putevalfv
end module modmain

program test_putevalfv
    use modmain
    implicit none
    integer :: ik
    character(len=10) :: fext = '.test'
    real(8), allocatable :: evalfv(:,:)

    allocate(vkl(3,1))
    vkl(:, 1) = (/1.0d0, 2.0d0, 3.0d0/)
    allocate(evalfv(nstfv, nspnfv))
    evalfv = reshape([1.1d0, 1.2d0, 2.1d0, 2.2d0], [nstfv, nspnfv])

    ik = 1

    call putevalfv(fext, ik, evalfv)

    deallocate(evalfv)
    deallocate(vkl)

    print *, "Test executed, check the EVALFV"//trim(fext)//" file for output."
end program test_putevalfv