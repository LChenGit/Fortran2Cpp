module Foo_mod

    implicit none
    private

    public :: someFunction
    public :: Foo

    type Foo
    end type Foo

contains

    function someFunction(inParam, outParam, inOutParam) result(returnValue)
        real, intent(in) :: inParam
        real, intent(out) :: outParam
        real, intent(inout) :: inOutParam
        real :: returnValue
        
        ! Operations based on the unit test
        outParam = inParam * 2.0
        inOutParam = inOutParam + 1.0
        returnValue = outParam + inOutParam
    end function someFunction

end module Foo_mod