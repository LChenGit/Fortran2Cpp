module FoX_wcml
  implicit none
contains

  subroutine cmlBeginFile()
    print *, "Beginning file..."
  end subroutine cmlBeginFile

  subroutine cmlFinishFile()
    print *, "Finishing file..."
  end subroutine cmlFinishFile

  subroutine cmlAddNamespace()
    print *, "Adding namespace..."
  end subroutine cmlAddNamespace

  subroutine cmlStartCml()
    print *, "Starting CML..."
  end subroutine cmlStartCml

  subroutine cmlEndCml()
    print *, "Ending CML..."
  end subroutine cmlEndCml

end module FoX_wcml