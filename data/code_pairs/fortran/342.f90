module random_ic_mod
  implicit none
contains
  function generate_random() result(r)
    real :: r
    call random_seed()
    call random_number(r)
  end function generate_random
end module random_ic_mod