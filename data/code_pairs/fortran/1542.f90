module HApplyMod
  implicit none
  private
  public :: HApply

contains

  subroutine HApply(enableOpenMP, perturbationLevel)
    logical, intent(in) :: enableOpenMP
    integer, intent(in) :: perturbationLevel

    print *, "OpenMP Enabled: ", enableOpenMP
    print *, "Perturbation Level: ", perturbationLevel
  end subroutine HApply

end module HApplyMod