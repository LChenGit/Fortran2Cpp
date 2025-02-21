#include <iostream>

class MyModule {
private:
    static int someVariable;
    
public:
    static void initialize() {
        if (!initialized) {
            someVariable = 0;
            initialized = true;
        }
    }
    
    static int getValue() {
        return someVariable;
    }
    
    static void setValue(int value) {
        someVariable = value;
    }
    
private:
    static bool initialized;
};

// Initialize static members
int MyModule::someVariable = 0;
bool MyModule::initialized = false;

int main() {
    // Initialize the module
    MyModule::initialize();
    
    try {
        // Retrieve and display initial value
        std::cout << "Initial value: " << MyModule::getValue() << std::endl;
        
        // Set a new value
        int newValue = 10;
        MyModule::setValue(newValue);
        
        // Retrieve and display updated value
        std::cout << "Value after setting: " << MyModule::getValue() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}