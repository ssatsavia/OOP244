
#define _CRT_SECURE_NO_WARNINGS
#include "Ticket.h"
#include "Patient.h" 
#include "TriagePatient.h"
#include <cstring> 
#include <string>
#include <iostream> 

namespace seneca {
    int TriagePatient::nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket++), m_symptoms(nullptr) {
        // Constructor initializes the patient with the current ticket number and increments the static ticket tracker
    }

    TriagePatient::~TriagePatient() {
        delete[] m_symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    std::ostream& TriagePatient::write(std::ostream& os) const {
        
        if (&os == &std::cout) {
            os << "TRIAGE" << std::endl;
            Patient::write(os); 
            nextTriageTicket = this->number() + 1;
            os << "Symptoms: " << m_symptoms << std::endl;
        }
        else if (&os == &std::clog){
            Patient::write(os);
        } 
        else {
            
            Patient::write(os) << "," << m_symptoms;
        }
        return os;
    }

    std::istream& TriagePatient::read(std::istream& is) {
        if (&is == &std::cin) {

            Patient::read(is);

            delete[] m_symptoms;
            std::cout << "Symptoms: ";
            char buf[512];
            is.getline(buf, 511);
            m_symptoms = new char[strlen(buf) + 1];
            strcpy(m_symptoms, buf);
        }
        else {
            Patient::read(is);
            delete[] m_symptoms;
            m_symptoms = nullptr; // Reset symptoms pointer
            is.ignore(1);  
            string symptoms;
            getline(is, symptoms, '\n'); // Read the rest of the line as symptoms 
            m_symptoms = new char[symptoms.length() + 1];
            strcpy(m_symptoms, symptoms.c_str());
        }
        return is;
    }
}
