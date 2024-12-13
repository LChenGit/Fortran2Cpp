MODULE MOD_Filter_Vars
    IMPLICIT NONE
    SAVE

    INTEGER                :: NFilter
    INTEGER                :: FilterType
    REAL                   :: HestFilterParam(3)
    REAL, ALLOCATABLE      :: FilterMat(:,:)
    LOGICAL                :: FilterInitIsDone = .FALSE.

    ! Variables that would be conditionally compiled
    REAL, ALLOCATABLE       :: lim(:)
    REAL, ALLOCATABLE       :: eRatio(:)
    REAL, ALLOCATABLE       :: r(:)
    REAL, ALLOCATABLE       :: ekin_avg_old(:)
    REAL, ALLOCATABLE       :: ekin_fluc_avg_old(:)
    REAL, ALLOCATABLE       :: IntegrationWeight(:,:,:,:,:)
    REAL                   :: normMod
    REAL                   :: LAF_alpha

    LOGICAL                :: DoPPLimiter
    INTEGER                :: iPPRefState
    REAL                   :: PPEpsFac
    REAL                   :: PPepsDens
    REAL                   :: PPepsPres
    INTEGER, ALLOCATABLE   :: PP_Elems(:)
    INTEGER, ALLOCATABLE   :: PP_Elems_counter(:)
    INTEGER                :: PP_Switch_counter
    REAL, ALLOCATABLE      :: PP_Elems_Amount(:)
END MODULE MOD_Filter_Vars