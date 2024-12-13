! test_atomic_operations.f90
program test_atomic_operations
    use iso_fortran_env, only: atomic_int_kind, atomic_logical_kind
    implicit none
    integer(atomic_int_kind) :: a
    integer(atomic_int_kind) :: b
    logical :: d
    logical :: e

    ! Initialize atomic variables
    a = 7
    b = a  ! Simulating atomic_ref for single-image
    d = .TRUE.
    e = .TRUE.

    ! Print results
    print *, "a: ", a
    print *, "b: ", b
    print *, "d: ", d
    print *, "e: ", e
end program test_atomic_operations