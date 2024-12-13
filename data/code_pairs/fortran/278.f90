module Mod_MBVariables
    implicit none
    integer(4)::incp
    
    real(8), dimension(:), allocatable :: Nslv, dNslvdxi, dNslv2dxi2
    real(8), dimension(:), allocatable :: Mslv, dMslvdeta, dMslv2deta2
    real(8), dimension(:), allocatable :: R1
    real(8), dimension(:,:), allocatable :: dR1, ddR1
    real(8), dimension(:), allocatable :: Rslv, gap
    real(8), dimension(:,:), allocatable :: dRslv, ddRslv
    real(8), dimension(:), allocatable :: Rmst
    real(8), dimension(:,:), allocatable :: dRmst, ddRmst
    integer(4), dimension(:), allocatable :: PTS_Active
    
    real(8), dimension(:,:), allocatable :: N, Na, Nb, Ta, tb
    real(8), dimension(:,:), allocatable :: Nhat, That, D, Nbar
    real(8), dimension(:,:), allocatable :: Kgeo, KG1, KG2, KG3, KG4
    
    real(8), dimension(:,:), allocatable :: KLM, FLM, GLM
    integer(4), dimension(:), allocatable :: disptempLM
    real(8), dimension(:,:), allocatable :: KeqLM, FeqLM, DispeqLM
    
    integer(4), dimension(:), allocatable :: PTS_conn
end module Mod_MBVariables