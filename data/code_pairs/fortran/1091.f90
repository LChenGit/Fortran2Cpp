program main
   use ISO_C_BINDING
   implicit none
   type, bind(C) :: descr
      type(C_PTR) :: address
   end type descr
   type(descr) :: DD
   double precision, target :: buf(1)
   integer (C_INTPTR_T) :: i, j

   buf = (/ 0 /)
   DD = descr(c_loc(buf))
   i = transfer (DD%address, 0_c_intptr_t)
   j = transfer (c_loc(buf), 0_c_intptr_t)
   if (any((/ i,j /) == 0_c_intptr_t)) STOP 1
   if (i /= j) STOP 2
   print *, "Test 1 Passed."
   print *, "Test 2 Passed."
   print *, "All tests passed."
end program main