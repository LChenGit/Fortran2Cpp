subroutine hcrit(xflow, rho, b, theta, dg, sqrts0, hk)
  implicit none
  double precision, intent(in) :: xflow, rho, b, theta, dg, sqrts0
  double precision, intent(out) :: hk
  double precision :: tth, c1, xflow2, A, dBBdh, dAdh, BB, dhk

  hk = (xflow / (rho * b))**2 / (dg * sqrts0)
  hk = hk**(1.d0 / 3.d0)

  if (abs(theta) < 1.d-10) return

  tth = tan(theta)
  c1 = rho * rho * dg * sqrts0
  xflow2 = xflow * xflow

  do
    A = hk * (b + hk * tth)
    dBBdh = 2.d0 * tth
    dAdh = b + hk * dBBdh
    BB = dAdh
    dhk = (xflow2 * BB - c1 * A**3) / (xflow2 * dBBdh - 3.d0 * c1 * A * A * dAdh)
    
    if (abs(dhk) / hk < 1.d-3) exit
    
    hk = hk - dhk
  end do
end subroutine hcrit