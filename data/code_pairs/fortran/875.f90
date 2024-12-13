subroutine plugin_summary()
  implicit none
  ! The body of plugin_summary is empty.
end subroutine plugin_summary

module test_plugin_summary_mod
  implicit none
contains
  subroutine test_plugin_summary()
    call plugin_summary()
    print *, "plugin_summary called successfully."
  end subroutine test_plugin_summary
end module test_plugin_summary_mod

program main
  use test_plugin_summary_mod
  implicit none
  call test_plugin_summary()
end program main