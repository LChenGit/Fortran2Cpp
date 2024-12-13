! ModSizeGitm.f90
module ModSizeGitm
    implicit none
    integer, parameter :: nAlts = 10
end module ModSizeGitm

! ModPlanet.f90
module ModPlanet
    implicit none
    integer, parameter :: nSpecies = 5
    integer, parameter :: nIonsAdvect = 3
    integer, parameter :: nSpeciesTotal = nSpecies + nIonsAdvect
end module ModPlanet