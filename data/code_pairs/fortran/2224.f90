MODULE cdf_aux_mod
  TYPE :: the_distribution
    INTEGER :: parameters(2)
  END TYPE the_distribution
  TYPE (the_distribution), PARAMETER :: the_beta = the_distribution((/99,999/))
CONTAINS
  SUBROUTINE set_bound(arg_name, test)
    INTEGER, INTENT (IN) :: arg_name, test
    if (arg_name .ne. test) STOP 'Bound check failed.'
  END SUBROUTINE set_bound
END MODULE cdf_aux_mod

MODULE cdf_beta_mod
  USE cdf_aux_mod
CONTAINS
  SUBROUTINE cdf_beta(which, test)
    INTEGER :: which, test
    CALL set_bound(the_beta%parameters(which), test)
  END SUBROUTINE cdf_beta
END MODULE cdf_beta_mod

PROGRAM test_cdf
  USE cdf_beta_mod
  IMPLICIT NONE
  CALL cdf_beta(1, 99)
  CALL cdf_beta(2, 999)
END PROGRAM test_cdf