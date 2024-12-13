CHARACTER*80 LIN_ERRMSG(0:3)
      COMMON /LIN_DATA/ LIN_ERRMSG

      DATA LIN_ERRMSG /
     :  'Success',
     :  'Null linprm pointer passed',
     :  'Memory allocation failed',
     :  'PCi_ja matrix is singular'/

      END