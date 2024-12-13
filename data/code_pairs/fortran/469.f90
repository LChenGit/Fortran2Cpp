module energy_calculations
    implicit none
    contains

    subroutine hardshellenergy(atom_count, coordinates, radius, energy)
        integer, intent(in) :: atom_count
        real, dimension(3,atom_count), intent(in) :: coordinates
        real, intent(in) :: radius
        real, intent(out) :: energy
        integer :: i, j
        real :: dx, dy, dz, dist

        energy = 0.0
        do i = 1, atom_count
            do j = i+1, atom_count
                dx = coordinates(1,i) - coordinates(1,j)
                dy = coordinates(2,i) - coordinates(2,j)
                dz = coordinates(3,i) - coordinates(3,j)
                dist = sqrt(dx**2 + dy**2 + dz**2)
                if (dist < radius) then
                    energy = energy + (radius - dist)**2
                end if
            end do
        end do
    end subroutine hardshellenergy

    subroutine hardshellenergy_gradient(atom_count, coordinates, radius, gradient)
        integer, intent(in) :: atom_count
        real, dimension(3,atom_count), intent(in) :: coordinates
        real, intent(in) :: radius
        real, dimension(3,atom_count), intent(out) :: gradient
        integer :: i, j
        real :: dx, dy, dz, dist, factor

        gradient = 0.0
        do i = 1, atom_count
            do j = i+1, atom_count
                dx = coordinates(1,i) - coordinates(1,j)
                dy = coordinates(2,i) - coordinates(2,j)
                dz = coordinates(3,i) - coordinates(3,j)
                dist = sqrt(dx**2 + dy**2 + dz**2)
                if (dist < radius) then
                    factor = 2.0 * (radius - dist) / dist
                    gradient(:,i) = gradient(:,i) - factor * (/dx, dy, dz/)
                    gradient(:,j) = gradient(:,j) + factor * (/dx, dy, dz/)
                end if
            end do
        end do
    end subroutine hardshellenergy_gradient

end module energy_calculations

program test_hardshellenergy
    use energy_calculations
    implicit none
    real, dimension(3,2) :: coordinates = reshape([1.0, 0.0, 0.0, 2.0, 0.0, 0.0], [3, 2])
    real :: radius = 1.5
    real :: energy
    real, dimension(3,2) :: gradient
    integer :: atom_count = 2

    call hardshellenergy(atom_count, coordinates, radius, energy)
    print *, "Energy Test: ", (abs(energy - 0.25) < 1.0e-5)

    call hardshellenergy_gradient(atom_count, coordinates, radius, gradient)
    print *, "Gradient Test: ", all(abs(gradient - reshape([1.0, -1.0, 0.0, 0.0, 0.0, 0.0], [3, 2])) < 1.0e-5)
end program test_hardshellenergy