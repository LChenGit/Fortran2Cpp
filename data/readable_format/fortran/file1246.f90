SUBROUTINE ALIGNP(CFX, CFY, CFZ, FXP, FYP, FZP, AKX1, AKX2, AKX3, AKX4, AKY1, &
     AKY2, AKY3, AKY4, AKZ1, AKZ2, AKZ3, AKZ4, DTSC)
  DOUBLE PRECISION CFX, CFY, CFZ, FXP, FYP, FZP, AKX1, AKX2, AKX3, AKX4, &
     AKY1, AKY2, AKY3, AKY4, AKZ1, AKZ2, AKZ3, AKZ4, DTSC

  FXP = FXP - DTSC*AKX4
  FYP = FYP - DTSC*AKY4
  FZP = FZP - DTSC*AKZ4
  CFX = AKX1*FXP + AKX2*FYP + AKX3*FZP
  CFY = AKY1*FXP + AKY2*FYP + AKY3*FZP
  CFZ = AKZ1*FXP + AKZ2*FYP + AKZ3*FZP
  FXP=0.
  FYP=0.
  FZP=0.
END SUBROUTINE ALIGNP

PROGRAM test_alignp
  IMPLICIT NONE

  DOUBLE PRECISION :: CFX, CFY, CFZ
  DOUBLE PRECISION :: FXP, FYP, FZP
  DOUBLE PRECISION :: AKX1, AKX2, AKX3, AKX4
  DOUBLE PRECISION :: AKY1, AKY2, AKY3, AKY4
  DOUBLE PRECISION :: AKZ1, AKZ2, AKZ3, AKZ4
  DOUBLE PRECISION :: DTSC

  ! Initialize variables
  FXP = 1.0
  FYP = 2.0
  FZP = 3.0
  AKX1 = 0.1
  AKX2 = 0.2
  AKX3 = 0.3
  AKX4 = 0.4
  AKY1 = 0.5
  AKY2 = 0.6
  AKY3 = 0.7
  AKY4 = 0.8
  AKZ1 = 0.9
  AKZ2 = 1.0
  AKZ3 = 1.1
  AKZ4 = 1.2
  DTSC = 0.01

  CALL ALIGNP(CFX, CFY, CFZ, FXP, FYP, FZP, AKX1, AKX2, AKX3, AKX4, &
              AKY1, AKY2, AKY3, AKY4, AKZ1, AKZ2, AKZ3, AKZ4, DTSC)

  PRINT *, 'CFX:', CFX, 'CFY:', CFY, 'CFZ:', CFZ
END PROGRAM test_alignp