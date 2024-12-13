module string_checks_mod
  implicit none
contains
  function isHelloWorld(c) result(res)
    character(len=*), intent(in) :: c
    logical :: res
    res = c == "Hello, world!"
  end function isHelloWorld
end module string_checks_mod

program testHelloWorld
  use string_checks_mod
  implicit none

  write(*,*) "Test 1 (Expect True): ", isHelloWorld("Hello, world!")
  write(*,*) "Test 2 (Expect False): ", isHelloWorld("Goodbye, world!")

end program testHelloWorld