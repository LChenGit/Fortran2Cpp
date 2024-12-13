module species_network
    implicit none

    integer, parameter :: max_species = 10
    character(len=10), dimension(max_species) :: species_names
    integer, dimension(max_species) :: atomic_numbers
    integer :: num_species = 0

contains

    subroutine init_network()
        species_names(1) = 'Hydrogen'
        atomic_numbers(1) = 1
        species_names(2) = 'Helium'
        atomic_numbers(2) = 2
        num_species = 2
    end subroutine init_network

    function find_species_index(name) result(index)
        character(len=*), intent(in) :: name
        integer :: index

        index = 0
        do i = 1, num_species
            if (trim(species_names(i)) == trim(name)) then
                index = i
                exit
            endif
        end do
    end function find_species_index

end module species_network