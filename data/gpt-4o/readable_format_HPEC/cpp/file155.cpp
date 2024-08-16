void domain()
{
    nx = nx0;
    ny = ny0;
    nz = nz0;

    if (nx < 4 || ny < 4 || nz < 4)
    {
        printf("SUBDOMAIN SIZE IS TOO SMALL - 
"
               "ADJUST PROBLEM SIZE OR NUMBER OF PROCESSORS 
"
               "SO THAT NX, NY AND NZ ARE GREATER THAN OR EQUAL 
"
               "TO 4 THEY ARE CURRENTLY %d %d %d
", nx, ny, nz);
        exit(1);
    }

    if (nx > isiz1 || ny > isiz2 || nz > isiz3)
    {
        printf("SUBDOMAIN SIZE IS TOO LARGE - 
"
               "ADJUST PROBLEM SIZE OR NUMBER OF PROCESSORS 
"
               "SO THAT NX, NY AND NZ ARE LESS THAN OR EQUAL TO 
"
               "ISIZ1, ISIZ2 AND ISIZ3 RESPECTIVELY.  THEY ARE 
"
               "CURRENTLY %d %d %d
", nx, ny, nz);
        exit(1);
    }

    ist = 2;
    iend = nx - 1;

    jst = 2;
    jend = ny - 1;

    ii1 = 2;
    ii2 = nx0 - 1;
    ji1 = 2;
    ji2 = ny0 - 2;
    ki1 = 3;
    ki2 = nz0 - 1;
}