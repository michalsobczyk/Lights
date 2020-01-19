#pragma once
#include "systemc.h"
#include "interface.h"

SC_MODULE(modul)
{
	sc_in<bool> clock;
	sc_in<bool> reset;
	sc_buffer<int> in;
	SC_CTOR(modul)
	{
		SC_THREAD(main);
		sensitive << clock.pos();
		sensitive << reset;
	}
	void main();

	class modul
	{
	};
};