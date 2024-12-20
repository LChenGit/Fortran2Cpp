DOUBLE PRECISION FUNCTION DDANRM (NEQ, V, WT, RPAR, IPAR)
  INTEGER  NEQ, IPAR(*)
  DOUBLE PRECISION  V(NEQ), WT(NEQ), RPAR(*)
  INTEGER  I
  DOUBLE PRECISION  SUM, VMAX
  DDANRM = 0.0D0
  VMAX = 0.0D0
  DO 10 I = 1,NEQ
    IF(ABS(V(I)/WT(I)) .GT. VMAX) VMAX = ABS(V(I)/WT(I))
10  CONTINUE
  IF(VMAX .LE. 0.0D0) GO TO 30
  SUM = 0.0D0
  DO 20 I = 1,NEQ
20  SUM = SUM + ((V(I)/WT(I))/VMAX)**2
  DDANRM = VMAX*SQRT(SUM/NEQ)
30  CONTINUE
  RETURN
END