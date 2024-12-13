! File: TEST.f90
MODULE TEST
  IMPLICIT NONE
  PRIVATE
  PUBLIC :: all_type, any_type
  
  TYPE :: info_type
     INTEGER :: value
  END TYPE info_type
  
  TYPE, PUBLIC :: all_type
     TYPE(info_type) :: info
  END TYPE all_type
  
  TYPE, PUBLIC :: any_type
     TYPE(info_type) :: info
  END TYPE any_type
  
END MODULE TEST

PROGRAM test_program
  USE TEST
  IMPLICIT NONE
  
  TYPE(all_type) :: example_all
  
  ! Test for all_type
  example_all%info%value = 5
  PRINT *, 'all_type value:', example_all%info%value
  
END PROGRAM test_program