program nombre_dor
  implicit none
  real :: computed_limite_suite, computed_nombre_or

  call compute_nombre_dor(computed_limite_suite, computed_nombre_or)
  print*, "Limite de la suite (vn) : ", computed_limite_suite
  print*, "Nombre d'or : ", computed_nombre_or
end program nombre_dor

subroutine compute_nombre_dor(limite_suite, nombre_or)
  implicit none
  real, parameter   :: epsilon = 1.e-5
  real              :: u_prec, u_cour
  real              :: v_prec, v_cour
  real              :: somme
  real, intent(out) :: nombre_or
  real, intent(out) :: limite_suite

  nombre_or = (1. + sqrt(5.))/2.

  u_prec = 1.; u_cour = 1.
  do
    v_prec = u_cour / u_prec
    somme  = u_cour + u_prec
    u_prec = u_cour
    u_cour = somme
    v_cour = u_cour / u_prec
    if ( abs( (v_cour - v_prec) / v_prec ) < epsilon ) exit
  end do

  limite_suite = v_cour
end subroutine compute_nombre_dor