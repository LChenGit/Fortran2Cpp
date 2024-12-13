program test_optimize_message
  implicit none
  call print_optimize_message

contains

subroutine print_optimize_message
  implicit none
  print *, 'Preprocessor: '
#ifdef ARTED_SC
  print *, '  ARTED_SC'
#endif
#ifdef ARTED_MS
  print *, '  ARTED_MS'
#endif
end subroutine print_optimize_message

end program test_optimize_message