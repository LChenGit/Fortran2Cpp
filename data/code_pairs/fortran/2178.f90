! Save this as clawpack46.f90
subroutine clawpack46_tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, refine_threshold, init_flag, tag_for_refinement)
  implicit none

  integer mx, my, mbc, meqn, tag_for_refinement, init_flag
  integer blockno
  double precision xlower, ylower, dx, dy
  double precision refine_threshold
  double precision q(1-mbc:mx+mbc, 1-mbc:my+mbc, meqn)

  integer i,j, mq
  double precision qx,qy

  tag_for_refinement = 0

  do mq = 1,meqn
     do i = 2,mx ! Start from 2 to use i-1 without going out of bounds
        do j = 2,my ! Start from 2 to use j-1 safely
           qx = (q(i+1,j,mq)-q(i-1,j,mq))/(2*dx)
           qy = (q(i,j+1,mq)-q(i,j-1,mq))/(2*dy)
           if (abs(qx) .gt. refine_threshold .or. abs(qy) .gt. refine_threshold) then
              tag_for_refinement = 1
              return
           endif
        enddo
     enddo
  enddo

end subroutine clawpack46_tag4refinement