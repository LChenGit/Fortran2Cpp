program main
  implicit none
  integer, dimension(2) :: a
  logical, dimension(2,1) :: lo
  logical, dimension(3) :: lo2
  integer :: sum
  integer :: product
  a = (/ 1, 2 /)
  lo = .true.
  lo2 = (/ .true., .true., .false. /)
  sum = 0
  product = 1

  ! Test sum and product with mask lo
  sum = sum(a, mask=lo)
  product = product(a, mask=lo)
  print *, "Testing sum with mask lo:", sum
  print *, "Expected: 3"
  print *, "Testing product with mask lo:", product
  print *, "Expected: 2"

  ! Reset sum and product for new tests
  sum = 0
  product = 1

  ! Test sum and product with mask lo2 (considering only the first 2 elements to match a's size)
  sum = sum(a, mask=lo2)
  product = product(a, mask=lo2)
  print *, "Testing sum with mask lo2:", sum
  print *, "Expected: 3"
  print *, "Testing product with mask lo2:", product
  print *, "Expected: 2"
end program main