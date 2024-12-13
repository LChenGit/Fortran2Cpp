module constants
        implicit none
        integer, parameter :: nn=25, ni=144, nj=288, nnaf=23, minc=6
        integer, parameter :: nnp2=nn+2, nnp1=nn+1, nn1=nn-1, nn2=nn-2
        integer, parameter :: nn3=nn-3, nps2=nnp1/2, ns2=nn1/2, nnx2=2*nn
        integer, parameter :: nja=nj/minc, nrp=nja+2, ncp=nrp/2
        integer, parameter :: ntf=3*nja/2+1, njp1=nj+1, nip1=ni+1
        integer, parameter :: lmax=(nj)/3, mmax=(lmax/minc)*minc, nmaf=mmax+1
        integer, parameter :: nmafa=mmax/minc+1
        integer, parameter :: nlm=(nmaf*(nmaf+1))/2, nlaf=lmax+1
        integer, parameter :: nlma=mmax*nlaf/minc-mmax*(mmax-minc)/(2*minc)+nlaf-mmax
        integer, parameter :: lot=2*nlma, nlafp1=nlaf+1, nlmpa=nlma+nmafa
      end module constants