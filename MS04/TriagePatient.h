
#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H

#include "Patient.h"

namespace seneca {
    class TriagePatient : public Patient {
        char* m_symptoms; // Dynamically allocated array for symptoms
        static int nextTriageTicket; 
    public:
        TriagePatient();
        virtual ~TriagePatient();
        virtual char type() const override;
        virtual std::ostream& write(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        TriagePatient(const TriagePatient&) = delete;
        TriagePatient& operator=(const TriagePatient&) = delete;
    };
}

#endif // TRIAGEPATIENT_H
