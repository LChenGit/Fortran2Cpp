subroutine dcovarxy(x, y, xmsg, ymsg, cxy, n, m, lag, ncrit, iopt)
    implicit none
    integer :: n, m, lag, ncrit, iopt
    double precision, dimension(n, m) :: x, y
    double precision :: xmsg, ymsg
    double precision, dimension(m, m) :: cxy
    integer :: i, j, k
    double precision :: sumxx, sumyy, sumxy, sumx, sumy, nxy, xvar, yvar

    cxy = 0.0
    do i = 1, m
        do j = 1, m
            nxy = 0.0
            sumx = 0.0
            sumy = 0.0
            sumxy = 0.0
            sumxx = 0.0
            sumyy = 0.0

            do k = lag + 1, n
                if (x(k, i) /= xmsg .and. y(k - lag, j) /= ymsg) then
                    nxy = nxy + 1
                    sumx = sumx + x(k, i)
                    sumy = sumy + y(k - lag, j)
                    sumxy = sumxy + x(k, i) * y(k - lag, j)
                    sumxx = sumxx + x(k, i) * x(k, i)
                    sumyy = sumyy + y(k - lag, j) * y(k - lag, j)
                end if
            end do

            if (nxy > 1.0d0 .and. nxy >= ncrit) then
                cxy(i, j) = (sumxy - (sumx * sumy) / nxy) / (nxy - 1.0d0)

                if (iopt == 1) then
                    xvar = (sumxx - (sumx * sumx) / nxy) / (nxy - 1.0d0)
                    yvar = (sumyy - (sumy * sumy) / nxy) / (nxy - 1.0d0)
                    cxy(i, j) = cxy(i, j) / (sqrt(xvar) * sqrt(yvar))
                end if
            else
                cxy(i, j) = xmsg
            end if
        end do
    end do
end subroutine