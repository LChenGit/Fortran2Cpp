MODULE hartree_variables
  IMPLICIT NONE
  PRIVATE
  PUBLIC :: E_hartree, Vh

  REAL(8) :: E_hartree
  REAL(8), ALLOCATABLE :: Vh(:)
END MODULE hartree_variables