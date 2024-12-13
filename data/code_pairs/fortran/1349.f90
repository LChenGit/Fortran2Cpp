CHARACTER(LEN=80) :: CEL_ERRMSG(0:6)
      COMMON /CEL_DATA/ CEL_ERRMSG

      DATA CEL_ERRMSG / &
     &  'Success', &
     &  'Null celprm pointer passed', &
     &  'Invalid projection parameters', &
     &  'Invalid coordinate transformation parameters', &
     &  'Ill-conditioned coordinate transformation parameters', &
     &  'One or more of the (x,y) coordinates were invalid', &
     &  'One or more of the (lng,lat) coordinates were invalid' /