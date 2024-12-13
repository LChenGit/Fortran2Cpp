program test
  implicit none

  if (.not..true. .eqv. .false.) then
    print *, "Test 1 passed"
  else
    print *, "Test 1 failed"
  end if

  if (.not..false. .eqv. .true.) then
    print *, "Test 2 passed"
  else
    print *, "Test 2 failed"
  end if

  if (.not..false..eqv..true. .eqv. .true.) then
    print *, "Test 3 passed"
  else
    print *, "Test 3 failed"
  end if

  if ('hello' .eq. 'hello') then
    print *, "Test 4 passed"
  else
    print *, "Test 4 failed"
  end if

  if (.not.('hello' .eq. 'world')) then
    print *, "Test 5 passed"
  else
    print *, "Test 5 failed"
  end if

  if ('hello world' == 'hello' // ' world') then
    print *, "Test 6 passed"
  else
    print *, "Test 6 failed"
  end if

end program test