program test_convw
    implicit none
    integer, parameter :: nsin = 10
    integer, parameter :: ndet = 5
    integer*2 :: in(nsin, ndet)
    double precision :: out(nsin, ndet)
    integer :: status
    integer :: i, j

    ! Define the SAI__OK constant
    integer, parameter :: SAI__OK = 0

    ! Initialize input data
    call init_input(in, nsin, ndet)

    status = SAI__OK
    call convw(in, nsin, ndet, 1, 5, out, status)

    ! Unit tests
    if (.not. has_close_elements(out, nsin, ndet, 100.0d0)) then
        write(*,*) "Test case 2 failed: assertion failed"
        call exit(1)
    end if

    if (.not. has_match_elements(in, out, nsin, ndet)) then
        write(*,*) "Test case 3 failed: output does not match input"
        call exit(1)
    end if

    write(*,*) "All unit tests passed."

contains

subroutine init_input(arr, n, m)
    integer*2 :: arr(n, m)
    integer :: n, m
    integer :: i, j

    do i = 1, n
        do j = 1, m
            arr(i, j) = i * j
        end do
    end do
end subroutine init_input

function has_close_elements(arr, n, m, threshold) result(res)
    double precision :: arr(n, m)
    integer :: n, m
    double precision :: threshold
    logical :: res
    integer :: i, j

    res = .true.
    do i = 1, n
        do j = 1, m
            if (arr(i, j) > threshold) then
                res = .false.
                return
            end if
        end do
    end do
end function has_close_elements

function has_match_elements(in, out, n, m) result(res)
    integer*2 :: in(n, m)
    double precision :: out(n, m)
    integer :: n, m
    logical :: res
    integer :: i, j

    res = .true.
    do i = 1, n
        do j = 1, m
            if (dble(out(i, j)) .ne. dble(in(i, j))) then
                res = .false.
                return
            end if
        end do
    end do
end function has_match_elements

subroutine convw(in, nsin, ndet, sbegin, send, out, status)
  implicit none
  integer :: nsin, ndet, sbegin, send, status
  double precision :: out(nsin, ndet)
  integer*2 :: in(nsin, ndet)
  integer :: i, j

  if (status .ne. SAI__OK) return

  do i = 1, nsin
    do j = 1, ndet
      out(i, j) = dble(in(i, j))
    end do
  end do
end subroutine convw
end program test_convw