! Assuming a module for company-related definitions for clarity
module company_defs
  implicit none
  integer, parameter :: max_company = 10
  integer, parameter :: c_company_id = 1, c_nmgr = 2, c_mgr_mem = 3, c_nwrkr = 4, c_wrkr_mem = 5
  integer :: c_table(max_company, 5)
end module company_defs

! Main program to test the build_company subroutine
program test_build_company
  use company_defs
  implicit none
  
  ! Initialize the c_table to simulate a clean slate
  c_table = -1 ! Using -1 to simulate MPI_UNDEFINED for this test
  
  ! Example call to the subroutine
  call build_company(1, 2, 3, 4, 5)
  if (c_table(1, c_company_id) /= 1) then
     print *, 'Test 1 failed: Company not added correctly.'
  else
     print *, 'Test 1 passed: Company added correctly.'
  endif
end program test_build_company

! The subroutine to be tested
subroutine build_company(id, nmgr, mgr_mem, nwrkr, wrkr_mem)
  use company_defs
  implicit none
  integer, intent(in) :: id, nmgr, mgr_mem, nwrkr, wrkr_mem
  integer :: i
  
  do i = 1, max_company
    if (c_table(i, c_company_id) == -1) then
      c_table(i, c_company_id) = id
      c_table(i, c_nmgr) = nmgr
      c_table(i, c_mgr_mem) = mgr_mem
      c_table(i, c_nwrkr) = nwrkr
      c_table(i, c_wrkr_mem) = wrkr_mem
      return
    endif
  end do
  
  print *, 'Error: Limit of ', max_company, ' companies has been exceeded.'
end subroutine build_company