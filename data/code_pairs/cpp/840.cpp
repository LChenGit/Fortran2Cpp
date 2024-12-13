#include <iostream>
#include <string>
#include <exception>

// Custom exception class to handle deallocation errors
class DeallocationException : public std::exception {
private:
    std::string message;
public:
    DeallocationException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Function to mimic Fortran's deallocate with error handling
template<typename T>
void safe_deallocate(T*& ptr, const std::string& errmsg) {
    if(ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    } else {
        if(errmsg != "Attempt to deallocate an unallocated object" && errmsg != "Attem") {
            throw DeallocationException(errmsg);
        } else {
            std::cout << "Attempt to deallocate caught as expected with message: " << errmsg << std::endl;
        }
    }
}

int main() {
    try {
        int* A = nullptr;  // Simulating unallocated variable
        int* B = new int[10]; // Simulating allocated array

        std::string longErrMsg(200, 'X');
        safe_deallocate(A, longErrMsg);

        std::string shortErrMsg(5, 'Q');
        safe_deallocate(A, shortErrMsg);

        // Ensure B is allocated before attempting to deallocate
        std::string deallocErrMsg = "Y";
        safe_deallocate(B, deallocErrMsg);

        shortErrMsg.assign(5, 'P');
        safe_deallocate(B, shortErrMsg); // B is already deallocated; expected to catch with short message

    } catch (const DeallocationException& e) {
        std::cerr << "Deallocation error: " << e.what() << '\n';
        std::abort();
    } catch (...) {
        std::cerr << "An unexpected error occurred.\n";
        std::abort();
    }

    return 0;
}