! aot_fun_declaration_module.f90
module aot_fun_declaration_module
  implicit none
  public :: aot_fun_type

  type :: aot_fun_type
    integer :: handle = 0
    integer :: arg_count = 0
  end type aot_fun_type

end module aot_fun_declaration_module