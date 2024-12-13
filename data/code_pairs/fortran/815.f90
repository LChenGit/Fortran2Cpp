subroutine get_loop_index(instr_index, index, subrange_flag)
  implicit none
  integer :: instr_index, index
  logical :: subrange_flag
  integer, parameter :: in_index_mask = 65536
  integer :: mask_val
  
  mask_val = iand(instr_index, in_index_mask)
  
  if (mask_val == 0) then
     subrange_flag = .false.
     index = instr_index
  else
     subrange_flag = .true.
     index = ieor(instr_index, in_index_mask)
  endif
end subroutine get_loop_index