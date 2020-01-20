#pragma once
#include "systemc.h"
#include "stdafx.h"
#include "interface.h"

class kolejka : public sc_channel, public write_if, public read_if
{
	sc_mutex muteks;
	sc_fifo<int> kolej;

public:
	kolejka(sc_module_name nazwa) :sc_channel(nazwa), kolej(24), muteks()
	{

	}

	void write(int wartosc)
	{
		muteks.lock();
		kolej.write(wartosc);
		muteks.unlock();
	}

	void read(int &wartosc)
	{
		kolej.read(wartosc);
	}

	void reset()
	{

	}

};
