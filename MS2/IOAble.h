//
//  IOable.hpp
//  MS2
//
//  Created by Sage Satsavia on 2024-03-15.
//

#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca {

    class IOAble {
    public:
        // Pure virtual functions
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;

        // Virtual destructor
        virtual ~IOAble() {}

        // Insertion and Extraction operator overloads
        friend std::ostream& operator<<(std::ostream& os, const IOAble& obj);
        friend std::istream& operator>>(std::istream& is, IOAble& obj);
    };

    // Insertion operator overload
    std::ostream& operator<<(std::ostream& os, const IOAble& obj) {
        return obj.write(os);
    }

    // Extraction operator overload
    std::istream& operator>>(std::istream& is, IOAble& obj) {
        return obj.read(is);
    }

} // namespace seneca

#endif // IOABLE_H

