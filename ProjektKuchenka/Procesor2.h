#pragma once
#include "systemc.h"
#include "interface.h"
#include "modul.h"
#include "kolejka.h"
#include "stdafx.h"

SC_MODULE(procesor2) {
	sc_in<bool> clock;
	sc_in<bool> reset;
	sc_port<read_if> in;
	kolejka *kolejka;
	SC_CTOR(procesor2) {

		SC_CTHREAD(main, clock.pos());

		SC_THREAD(zadanie2);
		sensitive << in;
		sensitive << reset;
	}

	void zadanie2();
	void main();

	~procesor2() {
		delete kolejka;
	}
};