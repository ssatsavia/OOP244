
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
#include <ostream>
namespace seneca {
	class IOAble
	{
	public:

		virtual ~IOAble() {};

		virtual std::ostream& write(std::ostream& out) const = 0;
		virtual std::istream& read(std::istream& in) = 0;

		friend std::ostream& operator<<(std::ostream& out, const IOAble& obj);
		friend std::istream& operator>>(std::istream& in, IOAble& obj);
	};

}

#endif // !IOABLE_H
