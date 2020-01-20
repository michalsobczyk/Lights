#pragma once
#include "systemc.h"
#include "interface.h"
#include "modul.h"
#include "kolejka.h"
#include "stdafx.h"

SC_MODULE(procesor1) {
	sc_in<bool> clock;
	sc_in<bool> reset;
	sc_port<write_if> out;
	sc_buffer<int> program;
	sc_out<bool> reset_out;
	modul *module;
	kolejka *kolejka;


	SC_CTOR(procesor1) {

		SC_THREAD(output);
		sensitive << program;
		sensitive << reset;

		SC_CTHREAD(input, clock.pos());
		sensitive << program;
		sensitive << reset;

		SC_THREAD(zadanie1);
		sensitive << program;
		sensitive << reset;

		SC_THREAD(zadanie3);
		sensitive << program;
		sensitive << reset;

		SC_THREAD(zadanie4);
		sensitive << program;
		sensitive << reset;

		SC_THREAD(zadanie5);
		sensitive << program;
		sensitive << reset;

		SC_THREAD(zadanie6);
		sensitive << program;
		sensitive << reset;
	}

	void input();
	void output();

	void zadanie1();
	void zadanie3();
	void zadanie4();
	void zadanie5();
	void zadanie6();
};