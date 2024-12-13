program foo
    implicit none
    complex(kind=8) z0, z1, z2

    z0 = (0.0d0, 0.5d0)
    z1 = 1.0d0 / z0
    if (z1 .ne. (0.0d0, -2.0d0)) stop 1

    z0 = 10.0d0 * z0
    if (z0 .ne. (0.0d0, 5.0d0)) stop 2

    z2 = (1.0d0, 2.0d0)
    z1 = z0 / z2
    if (z1 .ne. (2.0d0, 1.0d0)) stop 3

    z1 = z0 * z2
    if (z1 .ne. (-10.0d0, 5.0d0)) stop 4

end program foo