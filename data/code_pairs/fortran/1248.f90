module sin_module
  use, intrinsic :: iso_c_binding, only: c_float
  implicit none

contains

  function get_sin() result(fptr)
    interface
      pure real(c_float) function sin_interf(x)
        import :: c_float
        real(c_float), intent(in) :: x
      end function sin_interf
    end interface
    procedure(sin_interf), pointer :: fptr
    fptr => sin
  end function get_sin

end module sin_module

program test_sin
  use sin_module
  implicit none
  external :: test_sin_function

  call test_sin_function()

contains

  subroutine test_sin_function()
    use sin_module
    real(c_float), external :: get_sin
    interface
      function sin_fptr(x) result(res)
        import :: c_float
        real(c_float), intent(in) :: x
        real(c_float) :: res
      end function sin_fptr
    end interface
    procedure(sin_fptr), pointer :: fptr => null()
    real(c_float) :: result
    real(c_float), parameter :: input = 0.5_c_float ! Approx 30 degrees
    real(c_float) :: expected_value
    real(c_float), parameter :: tolerance = 0.0001_c_float

    fptr => get_sin()
    result = fptr(input)
    expected_value = sin(input)

    print *, "Testing sin function with input: ", input
    if (abs(result - expected_value) > tolerance) then
      print *, "Test Failed. Expected: ", expected_value, " Got: ", result
    else
      print *, "Test Passed. Result: ", result
    end if
  end subroutine test_sin_function

end program test_sin