module owner_module
    implicit none
contains
    integer function owner_block(ig, nx, np)
        integer :: ig, nx, np, r, q

        q = nx / np
        r = mod(nx, np)

        if (ig <= ((q + 1) * r)) then
            owner_block = (ig - 1) / (q + 1)
        else
            owner_block = ((ig - 1 - r) / q) + r
        end if
    end function owner_block

    integer function owner_cyclic(ig, nx, np)
        integer :: ig, nx, np

        owner_cyclic = mod(ig - 1, np)
    end function owner_cyclic

    integer function owner_block_cyclic(indxglob, nb, nprocs)
        integer :: indxglob, nb, nprocs

        owner_block_cyclic = mod((indxglob - 1) / nb, nprocs)
    end function owner_block_cyclic
end module owner_module

program test_owner_functions
    use owner_module
    implicit none

    print *, 'owner_block(5, 20, 4) = ', owner_block(5, 20, 4)
    print *, 'owner_cyclic(5, 20, 4) = ', owner_cyclic(5, 20, 4)
    print *, 'owner_block_cyclic(5, 4, 4) = ', owner_block_cyclic(5, 4, 4)
end program test_owner_functions