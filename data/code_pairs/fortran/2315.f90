program main
  character(len=40) :: c
  c = "Hello, world!"
  if (c /= "Hello, world!") then
    stop 1
  end if
end program main