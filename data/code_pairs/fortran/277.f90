subroutine norm(vel, velnorm, nef)
    implicit none
    integer :: i, j, nef
    real(8) :: velnorm(0:4)
    real(8) :: vel(nef,0:7)

    velnorm = 0.0d0

    !$OMP PARALLEL DEFAULT(NONE) SHARED(velnorm,vel,nef) PRIVATE(i,j)
    !$OMP DO REDUCTION(+:velnorm)
    do i = 1, nef
        do j = 0, 4
            velnorm(j) = velnorm(j) + vel(i,j)**2
        end do
    end do
    !$OMP END DO
    !$OMP END PARALLEL
end subroutine norm