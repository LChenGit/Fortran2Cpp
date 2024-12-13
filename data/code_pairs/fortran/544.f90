module kpoints
    
    implicit none

    ! Declarations
    integer nkpoints
    real, dimension (:, :), allocatable :: special_k
    real, dimension (:, :), allocatable :: special_k_orig
    real, dimension (:), allocatable :: weight_k
    real, dimension (:), allocatable :: weight_k_orig
    real, dimension (:, :), allocatable :: scale_k
    character (len = 40) kptpreference 

end module kpoints