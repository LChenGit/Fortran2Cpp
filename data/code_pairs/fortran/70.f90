! Note: This Fortran code assumes the use of a module or interface to bind cuBLAS functions.
! This example illustrates the structure and calls but omits specific cuBLAS bindings for brevity.

module mask_cublas
    use iso_c_binding
    implicit none
    contains

    subroutine cublas_setmat(Msize, matrix, dev_ptr)
        integer, intent(in) :: Msize
        real(kind=8), intent(in) :: matrix(Msize, Msize)
        type(c_ptr), intent(out) :: dev_ptr
        ! Your cuBLAS bindings and initialization here
        print *, "Setting matrix (actual cuBLAS implementation)."
    end subroutine

    subroutine cublas_release(dev_ptr)
        type(c_ptr), intent(inout) :: dev_ptr
        ! Your cuBLAS resource release here
        print *, "Releasing resources (actual cuBLAS implementation)."
    end subroutine

end module mask_cublas

program test_cublas
    use mask_cublas
    implicit none
    integer, parameter :: Msize = 2
    real(kind=8), dimension(Msize, Msize) :: matrix
    type(c_ptr) :: dev_ptr

    matrix = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(matrix))

    call cublas_setmat(Msize, matrix, dev_ptr)
    call cublas_release(dev_ptr)

    print *, "Fortran test completed successfully."
end program test_cublas