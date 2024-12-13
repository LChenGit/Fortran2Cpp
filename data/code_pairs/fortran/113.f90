module persons
  implicit none
  type :: person
    character(24) :: name = ""
    integer :: ss = 1
  end type person
end module persons

module person_education
  use persons
  implicit none
  type, extends(person) :: education
    integer :: attainment = 0
    character(24) :: institution = ""
  end type education
end module person_education

module service_module
  use person_education
  implicit none
  type, extends(education) :: service
    integer :: personnel_number = 0
    character(24) :: department = ""
  end type service
end module service_module

module person_record_module
  use service_module
  implicit none
  type, extends(service) :: person_record
    type(person_record), pointer :: supervisor => null()
  end type person_record
end module person_record_module

program personnel_management
  use person_record_module
  implicit none

  type(person_record), pointer :: recruit, supervisor

  ! Main program execution starts here
  ! Create a supervisor
  allocate(supervisor)
  supervisor%name = "Joe Honcho"
  supervisor%ss = 123455
  supervisor%attainment = 100
  supervisor%institution = "Celestial University"
  supervisor%personnel_number = 1
  supervisor%department = "Directorate"

  ! Create a recruit and assign a supervisor
  recruit => entry("John Smith", 123456, 1, "Bog Hill High School", 99, "Records", supervisor)

  ! Perform checks (Your checks here, based on your test logic)

  ! Deallocate pointers
  deallocate(supervisor)
  deallocate(recruit)

contains

  function entry(name, ss, attainment, institution, personnel_number, department, supervisor) result(new_person)
    type(person_record), pointer :: new_person
    integer, intent(in) :: ss, attainment, personnel_number
    character(len=*), intent(in) :: name, institution, department
    type(person_record), pointer, intent(in) :: supervisor

    allocate(new_person)
    new_person%name = name
    new_person%ss = ss
    new_person%attainment = attainment
    new_person%institution = institution
    new_person%personnel_number = personnel_number
    new_person%department = department
    new_person%supervisor => supervisor
  end function entry

end program personnel_management