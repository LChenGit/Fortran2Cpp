Function FirstNonChar(String, Char) Result(Position)
    Implicit None
    Character(*), Intent(In) :: String
    Character, Intent(In) :: Char
    Integer :: Position, i, LenString
    
    LenString = Len(Trim(String))
    Position = 0
    Do i = 1, LenString
        If (String(i:i) /= Char) Then
            Position = i
            Return
        End If
    End Do
End Function FirstNonChar