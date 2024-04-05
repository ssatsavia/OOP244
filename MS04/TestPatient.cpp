
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "TestPatient.h"

namespace seneca {

    int TestPatient::nextTestTicket = 1; // Initialize static member variable

    TestPatient::TestPatient() : Patient(nextTestTicket++) {
        // Constructor implementation
    }
    TestPatient::~TestPatient() = default;

    char TestPatient::type() const {
        return 'C'; // Specific for TestPatient
    }

    std::ostream& TestPatient::write(std::ostream& os) const {
        if (&os == &std::cout) {
            os << "Contagion TEST\n";
        }
        return Patient::write(os); // Call base class write and return the result
    }

    std::istream& TestPatient::read(std::istream& is) {
        Patient::read(is); // Call base class read
        if (&is != &std::cin) {
            nextTestTicket = this->number() + 1;
        }
        return is;
    }

} 
