BLOCK DATA FITSHDR_BLOCK_DATA
  CHARACTER*80 FITSHDR_ERRMSG(0:2)
  COMMON /FITSHDR_DATA/ FITSHDR_ERRMSG

  DATA FITSHDR_ERRMSG / &
       'Success', &
       'Null fitskey pointer-pointer passed', &
       'Memory allocation failed' /
END