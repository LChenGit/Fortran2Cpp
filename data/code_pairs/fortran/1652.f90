module type_decl
  implicit none
  type fcnparms
    integer :: i
  end type fcnparms
end module type_decl

module test
  use type_decl
  implicit none
contains
  subroutine sim_1(func1, params)
    interface
      function func1(fparams)
        use type_decl
        type(fcnparms), intent(in) :: fparams
        real :: func1
      end function func1
    end interface
    type(fcnparms), intent(in) :: params
    real :: result
    result = func1(params)  ! Assuming func1 does something and returns a real value
    print *, "sim_1 result: ", result
  end subroutine sim_1

  subroutine sim_2(func2, params)
    interface
      function func2(fparams)
        use type_decl
        type(fcnparms), intent(in) :: fparams
        real :: func2
      end function func2
    end interface
    type(fcnparms), intent(in) :: params
    real :: result
    result = func2(params)  ! Assuming func2 does something and returns a real value
    print *, "sim_2 result: ", result
  end subroutine sim_2
end module test

program main
  use test
  implicit none
  type(fcnparms) :: params

  params%i = 10
  call sim_1(test_func, params)
  call sim_2(test_func, params)

contains
  function test_func(fparams) result(res)
    use type_decl
    type(fcnparms), intent(in) :: fparams
    real :: res
    res = fparams%i * 2.0
  end function test_func
end program main