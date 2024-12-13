module great_relations_mod
    implicit none
    private
    public :: check_relationship

contains

    function check_relationship(from, to) result(is_great)
        character(len=*), intent(in) :: from, to
        logical :: is_great

        is_great = .false.

        ! Define relationships
        if ((from == "i1" .and. to == "x1") .or. &
            (from == "c1" .and. to == "a1") .or. &
            (from == "a1" .and. to == "o1") .or. &
            ! Add all other relationships here as needed...
            (from == "z1" .and. to == "g1")) then
            is_great = .true.
        endif
    end function check_relationship

end module great_relations_mod