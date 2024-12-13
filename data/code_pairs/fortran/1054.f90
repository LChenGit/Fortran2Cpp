module dump_lua_fif_module
  use, intrinsic :: iso_c_binding
  implicit none

  interface
    function dump_lua_toBuf(L, length, ierr) bind(C, name="dump_lua_toBuf")
      import :: c_ptr, c_int
      type(c_ptr), value :: L
      integer(c_int), value :: length
      integer(c_int) :: ierr
      type(c_ptr) :: dump_lua_toBuf
    end function dump_lua_toBuf
  end interface

end module dump_lua_fif_module