module binding_label_tests_8
  use, intrinsic :: iso_c_binding, only: c_int
  integer(c_int), bind(c, name='my_global_var') :: my_c_int = 0

contains

  subroutine my_f90_sub() bind(c)
    my_c_int = my_c_int + 10
  end subroutine my_f90_sub

end module binding_label_tests_8