module clawpack46_module
  implicit none
  integer :: blockno_com = -1
contains
  subroutine clawpack46_set_block(blockno)
    implicit none
    integer :: blockno
    blockno_com = blockno
  end subroutine clawpack46_set_block

  function fc2d_clawpack46_get_block() result(blockno_com_func)
    implicit none
    integer :: blockno_com_func
    blockno_com_func = blockno_com
  end function fc2d_clawpack46_get_block

  subroutine clawpack46_unset_block()
    implicit none
    blockno_com = -1
  end subroutine clawpack46_unset_block
end module clawpack46_module