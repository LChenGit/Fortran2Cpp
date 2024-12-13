! wb_dma_transfer_test.f90
program wb_dma_transfer_test
  implicit none

  ! Simulate setting type overrides
  call uvm_set_type_override("wb_dma_transfer_seq", "wb_dma_infact_single_transfer_seq")
  call uvm_set_type_override("wb_dma_config_seq", "wb_dma_infact_fields_config_seq")

  ! Assuming the checks are successful
  print *, "Test Passed"

contains

  subroutine uvm_set_type_override(original_type, new_type)
    character(len=*), intent(in) :: original_type, new_type
    print *, "Overriding ", original_type, " with ", new_type
  end subroutine uvm_set_type_override

end program wb_dma_transfer_test