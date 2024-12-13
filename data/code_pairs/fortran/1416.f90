module string_utils
  implicit none
contains
  PURE FUNCTION s_to_c(string) result(res)
    CHARACTER(LEN=*), INTENT(IN) :: string
    CHARACTER(LEN=:), ALLOCATABLE :: res
    res = string
  END FUNCTION s_to_c
end module string_utils