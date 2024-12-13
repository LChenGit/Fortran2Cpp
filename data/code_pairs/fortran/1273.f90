module basechange_mod
  implicit none
contains
  subroutine basechange_d(d)
    double precision, intent(in) :: d
    print *, 'basechange_d with input:', d
  end subroutine basechange_d

  subroutine basechange_c(c)
    complex, intent(in) :: c
    print *, 'basechange_c with input:', c
  end subroutine basechange_c

  subroutine basechange_z(z)
    complex(kind=16), intent(in) :: z
    print *, 'basechange_z with input:', z
  end subroutine basechange_z
end module basechange_mod