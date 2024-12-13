program test_constants
  implicit none
  integer, parameter :: ntq=200, ntc=0, nss=1
  integer, parameter :: nt=ntq+nss*ntc
  integer, parameter :: ng0=100, ng=ntq*ng0, nl=13
  integer, parameter :: ngd0=500, ngd=ntq*ngd0
  integer, parameter :: ntqss=ntq+nss
  integer, parameter :: norbit=800, Ngrid=0

  print *, 'ntq: ', ntq
  print *, 'ntc: ', ntc
  print *, 'nss: ', nss
  print *, 'nt: ', nt
  print *, 'ng0: ', ng0
  print *, 'ng: ', ng
  print *, 'nl: ', nl
  print *, 'ngd0: ', ngd0
  print *, 'ngd: ', ngd
  print *, 'ntqss: ', ntqss
  print *, 'norbit: ', norbit
  print *, 'Ngrid: ', Ngrid
end program test_constants