module matrix_operations_mod
    implicit none
contains
    subroutine mass_matrix(MM1)
        double precision, parameter :: m1 = 1.d0
        double precision, dimension(3,2), parameter :: A1 = reshape([1.d0,0.d0, &
             0.d0,0.d0,1.d0,0.d0],[3,2])
        double precision, dimension(2,2), parameter :: Mel = reshape([1.d0/3.d0, 0.d0, &
             0.d0, 1.d0/3.d0],[2,2])

        double precision, dimension(3,3) :: MM1

        MM1 = m1 * matmul(A1, matmul(Mel, transpose(A1)))
    end subroutine mass_matrix
end module matrix_operations_mod