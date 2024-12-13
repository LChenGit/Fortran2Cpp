SUBROUTINE ARGCH2(KEY,RA,DEC,IH,AM,ISGN,ID,AMIN)                        
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)                                     
      CHARACTER*1 ISGN,IMINUS,IPLUS                                           
      DOUBLE PRECISION RA, DEC, AM, AMIN, RAD, H, D, HOURS, DEG
      INTEGER KEY, IH, ID
      DATA IPLUS,IMINUS /'+','-'/                                             
      DATA RAD/0.0174532925199D0/                                             
      IF(KEY.EQ.-1) GO TO 10                                                  
      H=IH                                                                    
      D=ID                                                                    
      RA=15.D0*(H+AM/60.D0)* RAD                                               
      DEC=(D+AMIN/60.D0)*RAD                                                   
      IF(ISGN.EQ.'-') DEC=-DEC                                                
      RETURN                                                                  
 10   HOURS=RA/RAD/15.D0                                                      
      HOURS=DMOD(HOURS,24.D0)                                                 
      IH=INT(HOURS)                                                                
      AM=(HOURS-IH)*60.D0                                                      
      AM=AM+1.D-6                                                             
      IF(AM.LT.60.D0) GO TO 12                                                 
      AM=AM-60.D0                                                              
      IH=IH+1                                                                 
 12   IF(IH.GE.24) IH=IH-24                                                   
      IF(DEC.LT.0) THEN
        ISGN=IMINUS                                                             
      ELSE
        ISGN=IPLUS                                                              
      END IF
      DEG=ABS(DEC)/RAD                                                       
      ID=INT(DEG)                                                                  
      AMIN=(DEG-ID)*60.D0                                                      
      RETURN                                                                  
END