module Block_File_Names
    implicit none
    character(len=200) :: inPrefix = "input_"
    character(len=200) :: outPrefix = "output_"
    character(len=200) :: Flow_File = "flow.dat"
    character(len=200) :: Heat_File = "heat.dat"
    character(len=200) :: Init_File = "init.dat"
    character(len=200) :: Net_File = "net.dat"
    character(len=200) :: NPS_File = "nps.dat"
    character(len=200) :: Param_File = "param.dat"
    character(len=200) :: Source_File = "source.dat"
    character(len=200) :: Spatial_File = "spatial.dat"
end module Block_File_Names