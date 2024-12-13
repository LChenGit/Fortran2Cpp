! m_common_charset.f90
module m_common_charset
  implicit none
  integer, parameter :: XML1_0 = 1, XML1_1 = 2
end module m_common_charset

! m_common_struct.f90
module m_common_struct
  use m_common_charset, only : XML1_0, XML1_1
  implicit none
  type xml_doc_state
     integer :: xml_version = XML1_0
  end type xml_doc_state
end module m_common_struct

! m_common_namecheck.f90
module m_common_namecheck
  use m_common_struct, only : xml_doc_state
  implicit none
contains
  function checkQName(name, xds) result(isValid)
    character(len=*), intent(in) :: name
    type(xml_doc_state), intent(in) :: xds
    logical :: isValid

    isValid = .true.
    if (len(trim(name)) == 0 .or. name(1:1) == '1' .or. name(1:1) == ':' .or. name(1:1) == '#') then
       isValid = .false.
    else if (index(name, ':') /= 0 .and. xds%xml_version == XML1_0) then
       isValid = .false.
    endif
  end function checkQName
end module m_common_namecheck

! test_namecheck.f90
program test_namecheck
  use m_common_charset, only : XML1_0, XML1_1
  use m_common_struct, only : xml_doc_state
  use m_common_namecheck, only : checkQName
  implicit none

  type(xml_doc_state) :: xds
  logical :: result

  result = checkQName('abcd', xds)
  print *, result
  result = checkQName('1abcd', xds)
  print *, result
  result = checkQName(':abcd', xds)
  print *, result
  result = checkQName('#abcd', xds)
  print *, result
  result = checkQName('e:abcd', xds)
  print *, result

  xds%xml_version = XML1_1

  result = checkQName('abcd', xds)
  print *, result
  result = checkQName('1abcd', xds)
  print *, result
  result = checkQName(':abcd', xds)
  print *, result
  result = checkQName('#abcd', xds)
  print *, result
  result = checkQName('e:abcd', xds)
  print *, result
end program test_namecheck