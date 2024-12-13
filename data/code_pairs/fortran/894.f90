module Storage_module
    implicit none
    private
    public :: Storage_t, newStorage

    integer, parameter :: RP = selected_real_kind(15, 307)
    integer, parameter :: NCONS = 5
#ifdef NAVIER_STOKES
    integer, parameter :: NDIM = 3
#endif

    type Storage_t
        real(kind=RP), allocatable :: Q(:)
        real(kind=RP), allocatable :: QDot(:)
#ifdef NAVIER_STOKES
        real(kind=RP), allocatable :: dQ(:)
#endif
    contains
        procedure :: AllocateMemory => Storage_AllocateMemory
    end type Storage_t

contains

    function newStorage() result(val)
        type(Storage_t) :: val
        ! No need to allocate here as they are automatically deallocated
    end function newStorage

    subroutine Storage_AllocateMemory(self, totalPolynomialOrder)
        class(Storage_t), intent(inout) :: self
        integer, intent(in) :: totalPolynomialOrder

        if (allocated(self%Q)) deallocate(self%Q)
        if (allocated(self%QDot)) deallocate(self%QDot)
        allocate(self%Q(NCONS * totalPolynomialOrder))
        self%Q = 0.0_RP
        allocate(self%QDot(NCONS * totalPolynomialOrder))
        self%QDot = 0.0_RP
#ifdef NAVIER_STOKES
        if (allocated(self%dQ)) deallocate(self%dQ)
        allocate(self%dQ(NCONS * NDIM * totalPolynomialOrder))
        self%dQ = 0.0_RP
#endif
    end subroutine Storage_AllocateMemory

end module Storage_module