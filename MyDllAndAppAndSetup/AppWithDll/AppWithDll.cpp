// AppWithDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Dll/Dll.h"
#include <chrono>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <direct.h> 

using namespace std::chrono;
using namespace std;

int main()
{
	pradeti_laikma();
	cout << "Programa vykdys funkcijas su laiko prie kompiuterio apribojimo funkcija. " << endl;
	cout << "Norint testi spauskite 1, norint istestuoti ping ir valdymo skydo komponente spauskite 2" << endl;
	int pasirinkimas;
	string vardas;
	int k;
	string val;
	const int studento_id = 2313999;
	double intervalo_pr = -(studento_id % 19);
	double intervalo_pab = (studento_id % 25);
	double zin =  studento_id / 1e10;
	double r1 = -2;
	string failasr1 = "F-2.txt";
	double r2 = -1;
	string failasr2 = "F-1.txt";
	double r3 = 0;
	string failasr3 = "F0.txt";
	double r4 = 1;
	string failasr4 = "F1.txt";
	double r5 = 2;
	string failasr5 = "F2.txt";
	cin >> pasirinkimas;
	int blok;
	switch (pasirinkimas) {
	case 1:
		cout << "Ar norite blokuoti laika? Taip- 1, Ne- 2: ";
		cin >> blok;
		if (blok == 1) {
			cout << "Iveskite naudotojo varda, kuriam blokuosite laika: ";
			cin >> vardas;
			cout << "Iveskite dienu skaiciu per savaite, kuriomis bus ribojamas laikas: ";
			cin >> k;
			cout << "Iveskite valandas, kuriomis blokuosite laika (pvz. 09:00-15:00): ";
			cin >> val;
			apribojimas(vardas.c_str(), k, val.c_str());
		}
		kurti_folder();
		cout << "Programa atliko nauju aplankalu kurima." << endl;
		kilpa(r1, intervalo_pr, intervalo_pab, zin, failasr1.c_str());
		cout << "F=-2 skaiciavimai atlikti ir irasyti i failus. " << endl;
		kilpa(r2, intervalo_pr, intervalo_pab, zin, failasr2.c_str());
		cout << "F=-1 skaiciavimai atlikti ir irasyti i failus. " << endl;
		kilpa(r3, intervalo_pr, intervalo_pab, zin, failasr3.c_str());
		cout << "F=0 skaiciavimai atlikti ir irasyti i failus. " << endl;
		kilpa(r4, intervalo_pr, intervalo_pab, zin, failasr4.c_str());
		cout << "F=1 skaiciavimai atlikti ir irasyti i failus. " << endl;
		kilpa(r5, intervalo_pr, intervalo_pab, zin, failasr5.c_str());
		cout << "F=2 skaiciavimai atlikti ir irasyti i failus. " << endl;
		cout << "Tsrinhauseno kilpos skaiciavimai atlikti ir irasyti i failus. " << endl;
		cout << "Anksciau sukurti .txt failai bus sulieti i bendra sujungti_duomenys.txt faila aplankale 'naujas'." << endl;
		
		sulieti_failus(failasr1.c_str());
		cout << "F=-2 skaiciavimai sulieti ir irasyti i faila sulieti_duomenys_F-2.txt. " << endl;
		sulieti_failus(failasr2.c_str());
		cout << "F=-1 skaiciavimai sulieti ir irasyti i faila sulieti_duomenys_F-1.txt. " << endl;
		sulieti_failus(failasr3.c_str());
		cout << "F=0 skaiciavimai sulieti ir irasyti i faila sulieti_duomenys_F0.txt. " << endl;
		sulieti_failus(failasr4.c_str());
		cout << "F=1 skaiciavimai sulieti ir irasyti i faila sulieti_duomenys_F1.txt. " << endl;
		sulieti_failus(failasr5.c_str());
		cout << "F=2 skaiciavimai sulieti ir irasyti i faila sulieti_duomenys_F2.txt. " << endl;
		cout << "Programa istryne anksciau sukurtus aplankalus.";
		istrinti_folder();
		break;
	case 2:
		string adres;
		cout << "Iveskite adresa, kuri norite papinginti: ";
		cin >> adres;
		ping(adres.c_str());
		
		break;
	}
	double elapsed_time = gauti_vykdymo_laika();
	cout << "Programos vykdymo laikas: " << elapsed_time << " min." << endl;
	return 0;
}