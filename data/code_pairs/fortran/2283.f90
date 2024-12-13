program pr95869
  implicit none

  integer, parameter :: N = 100
  integer, parameter :: LIMIT = 60
  integer :: i, j
  integer, dimension(N) :: a

  ! Initialize the array a
  do i = 1, N
     a(i) = i
  end do

  do j = 1, N
    !$omp parallel do if(j .lt. LIMIT) shared(a)
    do i = 1, N
      a(i) = a(i) + 1
    end do
    !$omp end parallel do
  end do

  ! Verification step (Output for demonstration)
  do i = 1, N
    if (i == 1 .or. i == N) then
      print *, "a(", i, ")=", a(i)
    end if
  end do

end program pr95869