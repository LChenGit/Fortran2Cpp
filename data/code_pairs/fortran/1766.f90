MODULE CREATE_REGIONS_MESH__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE CREATE_REGIONS_MESH(IREGION_CODE, NSPEC, NGLOB_THEOR, NPOINTOT, &
       NEX_PER_PROC_XI, NEX_PER_PROC_ETA, NSPEC2DMAX_XMIN_XMAX, NSPEC2DMAX_YMIN_YMAX, &
       NSPEC2D_BOTTOM, NSPEC2D_TOP, OFFSET_PROC_XI, OFFSET_PROC_ETA, IPASS)
    INTEGER(KIND=4) :: IREGION_CODE, NSPEC, NGLOB_THEOR, NPOINTOT
    INTEGER(KIND=4) :: NEX_PER_PROC_XI, NEX_PER_PROC_ETA
    INTEGER(KIND=4) :: NSPEC2DMAX_XMIN_XMAX, NSPEC2DMAX_YMIN_YMAX
    INTEGER(KIND=4) :: NSPEC2D_BOTTOM, NSPEC2D_TOP
    INTEGER(KIND=4) :: OFFSET_PROC_XI, OFFSET_PROC_ETA, IPASS
    ! Implementation of the subroutine
    PRINT *, "CREATE_REGIONS_MESH called with IPASS:", IPASS
  END SUBROUTINE CREATE_REGIONS_MESH
END MODULE CREATE_REGIONS_MESH__genmod