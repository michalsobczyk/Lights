#pragma once
#include <systemc.h>
class write_if : virtual public sc_interface
{
public:
	virtual void write(int) = 0;
	virtual void reset() = 0;
};

class read_if : virtual public sc_interface
{
public:
	virtual void read(int &) = 0;
};

class interface
{
};
