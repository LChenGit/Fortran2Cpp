module work_type_mod
    implicit none
    private

    public :: work_type, init_work_type

    type work_type
        integer :: ntotal_kernel
        integer :: ndimensions
        integer :: nvertices
        real, allocatable :: vertices(:,:)
        real, allocatable :: kernel_values(:,:)
    end type work_type

contains

    subroutine init_work_type(wt, nkern, ndim, nverts)
        type(work_type), intent(out) :: wt
        integer, intent(in) :: nkern, ndim, nverts

        wt%ntotal_kernel = nkern
        wt%ndimensions = ndim
        wt%nvertices = nverts

        allocate(wt%vertices(1:wt%ndimensions, 1:wt%nvertices))
        allocate(wt%kernel_values(1:wt%ntotal_kernel, 1:wt%nvertices))
        wt%vertices = 0.0
        wt%kernel_values = 0.0
    end subroutine init_work_type

end module work_type_mod