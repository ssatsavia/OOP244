
#ifndef TESTPATIENT_H
#define TESTPATIENT_H

#include "Patient.h"
#include <iostream>

namespace seneca {

    class TestPatient : public Patient {
        static int nextTestTicket; // Correct placement as a private static member

    public:
        TestPatient();
        virtual ~TestPatient() override; // Ensure virtual destructor is correctly marked

        virtual char type() const override;
        virtual std::ostream& write(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;
    };

} // namespace seneca

#endif // TESTPATIENT_H
