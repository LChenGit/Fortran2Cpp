#ifndef EQUIVALENCE_GROUP_H
#define EQUIVALENCE_GROUP_H

class EquivalenceGroup {
public:
    union {
        float a;
        float b;
        float c;
    };

    static float d;
    static int f;

    // Constructor to initialize static variables if needed
    EquivalenceGroup() {
        // Initialize if there's specific logic needed
    }

    static void setD(float newValue) {
        d = newValue;
    }

    static float getD() {
        return d;
    }

    static void setF(int newValue) {
        f = newValue;
    }

    static int getF() {
        return f;
    }
};

// Initialize static members
float EquivalenceGroup::d = 0;
int EquivalenceGroup::f = 0;

#endif //EQUIVALENCE_GROUP_H