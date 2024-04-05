#include <iostream>
#include <ostream>
#include "IOAble.h"
using namespace std;
namespace seneca {
    ostream& operator<<(ostream& out, const IOAble& obj) {
        return obj.write(out);
    }

    istream& operator>>(istream& in, IOAble& obj) {
        return obj.read(in);
    }
}
