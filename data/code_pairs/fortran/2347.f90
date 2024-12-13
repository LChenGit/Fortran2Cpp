MODULE kind_module
     
  IMPLICIT NONE 

  INTEGER, PARAMETER :: single = SELECTED_REAL_KIND(p=6, r=37)
  INTEGER, PARAMETER :: double = SELECTED_REAL_KIND(p=15, r=307)
  INTEGER, PARAMETER :: prec = double

  INTEGER, PARAMETER :: cSingle = KIND(1.0_single)
  INTEGER, PARAMETER :: cDouble = KIND(1.0_double)
  INTEGER, PARAMETER :: cPrec = cDouble
         
END MODULE kind_module