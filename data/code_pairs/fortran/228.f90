! ppm_module_tree_boxcost.f90
module ppm_module_tree_boxcost
    implicit none
    contains

    function ppm_tree_boxcost_s(x) result(cost)
        real, intent(in) :: x
        real :: cost
        cost = x * 2.0 ! Placeholder operation
    end function ppm_tree_boxcost_s

    function ppm_tree_boxcost_d(x) result(cost)
        double precision, intent(in) :: x
        double precision :: cost
        cost = x * 2.0d0 ! Placeholder operation
    end function ppm_tree_boxcost_d

end module ppm_module_tree_boxcost