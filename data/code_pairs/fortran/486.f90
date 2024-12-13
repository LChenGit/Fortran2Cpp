module ppm_module_util_gmres
   implicit none
   integer, parameter :: ppm_gmres_param_success = 0
   integer, parameter :: ppm_gmres_param_failure = 1
   integer, parameter :: ppm_gmres_param_maxiter = 2

contains

   function ppm_util_gmres_s() result(res)
       integer :: res
       print *, "Called single precision GMRES utility function."
       res = ppm_gmres_param_success
   end function ppm_util_gmres_s

   function ppm_util_gmres_d() result(res)
       integer :: res
       print *, "Called double precision GMRES utility function."
       res = ppm_gmres_param_success
   end function ppm_util_gmres_d

   function ppm_util_gmres_solveupper_s() result(res)
       integer :: res
       print *, "Called single precision solve upper function."
       res = ppm_gmres_param_success
   end function ppm_util_gmres_solveupper_s

   function ppm_util_gmres_solveupper_d() result(res)
       integer :: res
       print *, "Called double precision solve upper function."
       res = ppm_gmres_param_success
   end function ppm_util_gmres_solveupper_d

end module ppm_module_util_gmres

program test_gmres
   use ppm_module_util_gmres
   implicit none

   ! Test single precision GMRES
   call ppm_util_gmres_s()
   ! Test double precision GMRES
   call ppm_util_gmres_d()
   ! Test single precision solve upper
   call ppm_util_gmres_solveupper_s()
   ! Test double precision solve upper
   call ppm_util_gmres_solveupper_d()

end program test_gmres