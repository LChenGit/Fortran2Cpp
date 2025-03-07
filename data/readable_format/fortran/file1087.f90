MODULE model_defn
    IMPLICIT NONE
    CHARACTER(*), PARAMETER :: FUSE_version = "FUSE 1.0"
    LOGICAL, PARAMETER :: FUSE_enabled = .TRUE.
    INTEGER, PARAMETER :: NDEC = 9
    TYPE DESC
        CHARACTER(LEN=16) :: MCOMPONENT
    END TYPE DESC
    TYPE(DESC), DIMENSION(2) :: LIST_RFERR
    TYPE(DESC), DIMENSION(3) :: LIST_ARCH1
    TYPE(DESC), DIMENSION(4) :: LIST_ARCH2
    TYPE(DESC), DIMENSION(3) :: LIST_QSURF
    TYPE(DESC), DIMENSION(3) :: LIST_QPERC
    TYPE(DESC), DIMENSION(2) :: LIST_ESOIL
    TYPE(DESC), DIMENSION(2) :: LIST_QINTF
    TYPE(DESC), DIMENSION(2) :: LIST_Q_TDH
    TYPE(DESC), DIMENSION(2) :: LIST_SNOWM
    TYPE UMODEL
        INTEGER :: MODIX
        CHARACTER(LEN=256) :: MNAME
        INTEGER :: iRFERR
        INTEGER :: iARCH1
        INTEGER :: iARCH2
        INTEGER :: iQSURF
        INTEGER :: iQPERC
        INTEGER :: iESOIL
        INTEGER :: iQINTF
        INTEGER :: iQ_TDH
        INTEGER :: iSNOWM
    END TYPE UMODEL
    TYPE SNAMES
        INTEGER :: iSNAME
    END TYPE SNAMES
    TYPE FNAMES
        CHARACTER(LEN=16) :: FNAME
    END TYPE FNAMES
    INTEGER, PARAMETER :: NTDH_MAX = 500
    CHARACTER(LEN=256) :: FNAME_NETCDF_RUNS
    CHARACTER(LEN=256) :: FNAME_NETCDF_PARA
    CHARACTER(LEN=256) :: FNAME_NETCDF_PARA_SCE
    CHARACTER(LEN=256) :: FNAME_NETCDF_PARA_PRE
    CHARACTER(LEN=256) :: FNAME_PREFIX
    CHARACTER(LEN=256) :: FNAME_TEMPRY
    CHARACTER(LEN=256) :: FNAME_ASCII
    TYPE(UMODEL), DIMENSION(5000) :: AMODL
    TYPE(UMODEL) :: SMODL
    TYPE(SNAMES), DIMENSION(7) :: CSTATE
    INTEGER :: NSTATE = 0
    TYPE(FNAMES), DIMENSION(50) :: C_FLUX
    INTEGER :: N_FLUX = 0
END MODULE model_defn

PROGRAM testModelDefn
    USE model_defn
    IMPLICIT NONE

    PRINT *, "Module `model_defn` compiled successfully."
    PRINT *, "FUSE_version: ", FUSE_version
    PRINT *, "FUSE_enabled: ", FUSE_enabled
    PRINT *, "NDEC: ", NDEC
    PRINT *, "NTDH_MAX: ", NTDH_MAX
    
    ! Example of setting and accessing a DESC type
    LIST_RFERR(1)%MCOMPONENT = "Component1"
    PRINT *, "LIST_RFERR(1)%MCOMPONENT: ", LIST_RFERR(1)%MCOMPONENT
    
    ! Add more tests as needed...
END PROGRAM testModelDefn