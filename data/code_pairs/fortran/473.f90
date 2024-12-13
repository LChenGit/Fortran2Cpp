PROGRAM main
  IMPLICIT NONE
  INTEGER, TARGET :: arr(12), basem(3, 4)
  INTEGER, POINTER :: vec(:), mat(:, :)
  INTEGER :: i

  ! Initialize array with values 1 to 12
  arr = (/ (i, i = 1, 12) /)
  ! Reshape arr to match basem's shape
  basem = RESHAPE (arr, SHAPE (basem))

  ! Subset with pointers
  vec(2:5) => arr(1:12:2)
  ! Test subsetting
  IF (vec(2) /= 1 .OR. vec(5) /= 7) CALL abort()

  ! Reassign vec to point to every second element of arr
  vec => arr(1:12:2)
  ! Assign mat to point to vec in a reshaped manner
  mat(1:3, 1:2) => vec
  IF (mat(1, 1) /= 1 .OR. mat(3, 2) /= 11) CALL abort()

  ! Flatten basem and assign it to vec
  vec(1:12_1) => basem
  IF (vec(1) /= 1 .OR. vec(5) /= 5 .OR. vec(12) /= 12) CALL abort()

  PRINT *, "All tests passed successfully."
END PROGRAM main