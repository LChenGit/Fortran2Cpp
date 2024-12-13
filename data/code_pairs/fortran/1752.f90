! Main Fortran code with allocation and deallocation routines
module modes
    implicit none
    integer, parameter :: nat = 10 ! Example value
    integer, parameter :: npertx = 5 ! Example value
    real, allocatable :: t(:,:,:,:), tmq(:,:,:)
contains
    subroutine allocate_pert()
        implicit none
        allocate ( t ( npertx, npertx, 48, 3 * nat ) )
        allocate ( tmq ( npertx, npertx, 3 * nat ) )
    end subroutine allocate_pert

    subroutine deallocate_pert()
        implicit none
        if (allocated(t)) deallocate ( t )
        if (allocated(tmq)) deallocate ( tmq )
    end subroutine deallocate_pert
end module modes

program test_allocation
    use modes
    implicit none

    call allocate_pert
    print *, "Fortran Stdout: Allocation successful."
    call deallocate_pert
    print *, "Fortran Stdout: Deallocation successful."

end program test_allocation