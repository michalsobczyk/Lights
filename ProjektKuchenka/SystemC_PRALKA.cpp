
#include "stdafx.h"
#include "interface.h"
#include "procesor1.h"
#include "Procesor2.h"
#include "kolejka.h"

SC_MODULE(SYSTEM) {

	sc_clock clock_signal;
	sc_signal<bool> reset_signal;
	procesor1 *Proc1;
	procesor2 *Proc2;
	kolejka *kolej;
	SC_CTOR(SYSTEM) : clock_signal("clock_signal", 10, SC_NS)
	{
		kolej = new kolejka("kolejka");

		Proc1 = new procesor1("procesor1");
		Proc1->clock(clock_signal);
		Proc1->reset(reset_signal);
		Proc1->out(*kolej);
		Proc1->reset_out(reset_signal);

		Proc2 = new procesor2("procesor2");
		Proc2->clock(clock_signal);
		Proc2->reset(reset_signal);
		Proc2->in(*kolej);
	}
	~SYSTEM()
	{
		delete Proc1;
		delete Proc2;
		delete kolej;
	}
};

SYSTEM *top = NULL;

int sc_main(int argc, char** argv)
{
	top = new SYSTEM("top");
	sc_start();
	cout << "EPEPEP";
	getchar();
	return 0;
}

// dorota.dariusz@gmail.com
// KATALOG : SW_FILIPOWICZ_GOGOLA_SYSTEMC_PRALKA_2