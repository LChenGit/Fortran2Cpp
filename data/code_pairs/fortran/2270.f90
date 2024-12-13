program test_sqdist
    implicit none
    real*8 :: result
    real*8 :: x1, y1, z1, x2, y2, z2
    integer :: ind, MAXROT
    real*8 :: rotmat(1:3, 1:3, 1:3)

    ! Initialize test values
    x1 = 1.0
    y1 = 2.0
    z1 = 3.0
    x2 = 4.0
    y2 = 5.0
    z2 = 6.0
    ind = 1
    MAXROT = 3

    ! Initialize the rotation matrix to identity matrix for simplicity
    rotmat(:,:,1) = reshape((/ 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 /), shape(rotmat(:,:,1)))

    ! Call the function
    result = sqdist(x1, y1, z1, x2, y2, z2, ind, MAXROT, rotmat)

    ! Print the result
    print *, 'Squared distance:', result

contains

    real*8 function sqdist(x1, y1, z1, x2, y2, z2, ind, MAXROT, rotmat)
        real*8, intent(in) :: x1, y1, z1, x2, y2, z2
        integer, intent(in) :: ind, MAXROT
        real*8, intent(in) :: rotmat(MAXROT, 3, 3)
        real*8 :: cont, dx, dy, dz
        integer :: i

        dx = x1 - x2
        dy = y1 - y2
        dz = z1 - z2
        sqdist = 0.0
        do i = 1, 3
            cont = rotmat(ind, i, 1) * dx + &
                   rotmat(ind, i, 2) * dy + &
                   rotmat(ind, i, 3) * dz
            sqdist = sqdist + cont**2
        end do
    end function sqdist

end program test_sqdist