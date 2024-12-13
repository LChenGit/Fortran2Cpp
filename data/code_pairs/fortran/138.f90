module asdf_data

  type asdf_record
    real, pointer :: record(:)
  end type asdf_record

  type asdf_event
    character(len=13)     :: event
    integer           :: nreceivers
    character(len=20), pointer :: receiver_name_array(:), network_array(:)
    character(len=20), pointer :: component_array(:)
    character(len=20), pointer :: receiver_id_array(:)
    type (asdf_record), pointer :: records(:)
  end type asdf_event

end module asdf_data