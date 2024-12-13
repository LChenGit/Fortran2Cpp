module orders
  implicit none
contains
  logical function lt_dble(a, b)
    double precision, intent(in) :: a, b
    lt_dble = a < b
  end function lt_dble

  logical function lt_int(a, b)
    integer, intent(in) :: a, b
    lt_int = a < b
  end function lt_int

  logical function lt_real(a, b)
    real, intent(in) :: a, b
    lt_real = a < b
  end function lt_real

  logical function gtabs_dble(a, b)
    double precision, intent(in) :: a, b
    gtabs_dble = abs(a) > abs(b)
  end function gtabs_dble

  logical function gtabs_int(a, b)
    integer, intent(in) :: a, b
    gtabs_int = abs(a) > abs(b)
  end function gtabs_int

  logical function gtabs_real(a, b)
    real, intent(in) :: a, b
    gtabs_real = abs(a) > abs(b)
  end function gtabs_real

  logical function gt_dble(a, b)
    double precision, intent(in) :: a, b
    gt_dble = a > b
  end function gt_dble

  logical function gt_int(a, b)
    integer, intent(in) :: a, b
    gt_int = a > b
  end function gt_int

  logical function gt_real(a, b)
    real, intent(in) :: a, b
    gt_real = a > b
  end function gt_real
end module orders