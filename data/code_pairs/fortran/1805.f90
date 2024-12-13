module vast_kind_param
  integer, parameter :: double = selected_real_kind(15, 307)
end module vast_kind_param

module molkst_C
  use vast_kind_param, only: double
  implicit none
  integer :: maxatoms, natoms, numat = 0, norbs, nelecs, ndep = 0
  integer :: nvar = 0, nclose, nalpha, nbeta, nopen, numcal, mpack
  integer :: n2elec, nscf, iscf, iflepo, last, na1, lm61, lm6, dummy
  real(double) :: escf, emin, elect, enuclr, fract, gnorm
  real(double) :: time0 = 0.d0, tleft, tdump = 0.d0, verson = 7.1d0
  real(double) :: cosine, ux, uy, uz, step, rjkab1, atheat, efield(3), rdummy
  logical :: moperr, uhf, isok, limscf, is_PARAM = .false.
  character(len=1) :: ltxt
  character(len=80) :: jobnam
  character(len=241) :: keywrd, koment, title
  character(len=200) :: errtxt
  logical :: method_mndo, method_am1, method_pm3, method_mndod, method_dorbs, method
end module molkst_C