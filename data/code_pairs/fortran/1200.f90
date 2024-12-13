! derived_types.f90
program derived_types

    implicit none
    type book
        character(len=40) :: title
        character(len=40) :: author
        integer           :: year
        integer           :: ID
        character(len=40) :: publisher
    end type book

    type(book) :: book1
    type(book) :: book2

    book1%title     = "World"
    book1%author    = "Me"
    book1%year      = 1985
    book1%ID        = 12
    book1%publisher = "Venezia"

    book2%title     = "Friuli"
    book2%author    = "MT"
    book2%year      = 1946
    book2%ID        = 22
    book2%publisher = "Savorgnano"

    print *, "Book 1 Details:"
    print *, book1%title
    print *, book1%author
    print *, book1%year
    print *, book1%ID
    print *, book1%publisher

    print *, "Book 2 Details:"
    print *, book2%title
    print *, book2%author
    print *, book2%year
    print *, book2%ID
    print *, book2%publisher

end program derived_types