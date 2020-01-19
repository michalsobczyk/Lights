#include "stdafx.h"
#include "modul.h"
void modul::main() {
	int wartosc = in.read();
	int poprzedniaOpcja = 0;

	while (true)
	{
		wait();
		if (reset.read() == 1) {
			poprzedniaOpcja = 0;
			system("cls");
		}
		else {
			if (poprzedniaOpcja == 0) {
				if (wartosc == 2)
					cout << "Ogrzewanie prawej strony wlaczone z modulu" << endl;
				if (wartosc != 0 && wartosc != 1 && wartosc != 2 && wartosc != 3 && wartosc != 4 && wartosc != 5 && wartosc != 6)
					cout << "ERROR" << endl;
			}
			else {
				if (wartosc != 0)
					cout << "ERROR" << endl;
			}
			poprzedniaOpcja = wartosc;
		}
	}
}