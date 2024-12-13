// m.h
#pragma once

namespace m {

    struct t1 {
        int a = 42;
        int b;
    };

    struct t2 {
        int a = 0;
        int b = 0;
    };

    void sub1(t1& x) { /* t1's members are already correctly initialized. */ }

    void sub2(t2& x) { x.a = 42; /* Leaves b as is. */ }

    void sub3(t2& x) { /* Function intentionally left blank. */ }

} // End of namespace m