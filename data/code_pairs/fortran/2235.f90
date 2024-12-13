Program m5
  Implicit None
  Call s()
Contains
  Subroutine s
    Interface
      Function f()
        Real :: f
      End Function
      Function g()
        Real :: g
      End Function
    End Interface
    Print *, g()
    Print *, f()
    Print *, g()
  End Subroutine s

  Real Function f()
    f = 1.0
  End Function

  Real Function g()
    g = 2.0
  End Function
End Program m5