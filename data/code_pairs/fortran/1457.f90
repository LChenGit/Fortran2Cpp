program test_dh_board
implicit none

! Function declaration
double precision dh_board
external dh_board

! Common block variables
double precision fcr1, fcr2, dfcr1, dfcr2
double precision tcr1, tcr2, dtcr1, dtcr2, ampcr
common /brd_dh/ fcr1, fcr2, dfcr1, dfcr2, tcr1, tcr2, dtcr1, dtcr2, ampcr

! Initialize variables
fcr1 = 1.0
fcr2 = 5.0
dfcr1 = 0.5
dfcr2 = 0.5
tcr1 = 1.0
tcr2 = 5.0
dtcr1 = 0.5
dtcr2 = 0.5
ampcr = 10.0

! Test cases
print *, 'dh_board(2.0, 2.0) = ', dh_board(2.0, 2.0)
print *, 'dh_board(6.0, 2.0) = ', dh_board(6.0, 2.0)
print *, 'dh_board(2.0, 6.0) = ', dh_board(2.0, 6.0)
print *, 'dh_board(3.5, 3.5) = ', dh_board(3.5, 3.5)

end

double precision function dh_board(fi, tet)
implicit none
double precision, intent(in) :: fi, tet
double precision fcr1, fcr2, dfcr1, dfcr2
double precision tcr1, tcr2, dtcr1, dtcr2, ampcr
common /brd_dh/ fcr1, fcr2, dfcr1, dfcr2, tcr1, tcr2, dtcr1, dtcr2, ampcr

double precision f1, f2, t1, t2
integer nfi, ntet, ifi, itet
logical flag

dh_board = 0.0
flag = .false.

if ((fi - fcr1) * (fi - fcr2) > 0.0) return
if ((tet - tcr1) * (tet - tcr2) > 0.0) return

nfi = int((fcr2 - fcr1) / (dfcr1 + dfcr2))
ntet = int((tcr2 - tcr1) / (dtcr1 + dtcr2))

do ifi = 1, nfi
   f1 = fcr1 + (ifi - 1) * (dfcr1 + dfcr2)
   f2 = fcr1 + ifi * (dfcr1 + dfcr2)
   if ((fi - f1) * (fi - f2) <= 0.0) exit
end do

if (fi >= f1 + dfcr1) return

do itet = 1, ntet
   t1 = tcr1 + (itet - 1) * (dtcr1 + dtcr2)
   t2 = tcr1 + itet * (dtcr1 + dtcr2)
   if ((tet - t1) * (tet - t2) <= 0.0) exit
end do

if (tet >= t1 + dtcr1) return

dh_board = (-1)**(ifi + itet) * ampcr

end function dh_board