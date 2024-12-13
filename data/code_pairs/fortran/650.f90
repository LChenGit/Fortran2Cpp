module probleme_mod
  implicit none
contains

subroutine probleme(p, nx, nix)
  real(kind=8), dimension(:), intent(in) :: p
  integer, intent(out) :: nx, nix

  nx = size(p, 1)
  nix = nx

end subroutine probleme

end module probleme_mod