// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Dll.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <direct.h> 
#include <thread>
#include <mutex>
#include <sys/stat.h>
#include <sstream>
#include <ctime>
using namespace std::chrono;
using namespace std;
std::mutex failu_mutex; 


static steady_clock::time_point start_time;

extern "C" DLL_API void pradeti_laikma() {
    start_time = steady_clock::now();
}

extern "C" DLL_API double gauti_vykdymo_laika() {
    steady_clock::time_point end_time = steady_clock::now();
    duration<double, std::milli> elapsed_time = end_time - start_time;
    return elapsed_time.count() / 60000.0;
}

void vykdyti_cmd(const char* komanda) {
    string cmd = "powershell Start-Process cmd -ArgumentList '/c " + string(komanda) + "' -Verb RunAs";
    system(cmd.c_str());
}

int apribojimas(const char* username, int kiek, const char* valandos) {
    string kelias = "C:\\Users\\" + string(username) + "\\restriction.txt";

    ofstream F(kelias, ios::app);
    if (!F) {
        cout << "KLAIDA: Nepavyko sukurti failo: " << kelias << endl;
        return -1;
    }

    vector<string> dienos;
    for (int i = 0; i < kiek; i++) {
        string a;
        cout << "Iveskite savaites dienas, kurias norite blokuoti (M, T, W, Th, F, Sa, Su): ";
        cin >> a;
        dienos.push_back(a);
    }

    F << "Naudotojas: " << username << " apribotas siomis dienomis: ";
    for (const auto& d : dienos) {
        F << d << " ";
    }
    F << "valandomis: " << valandos << endl;
    F.close();

    string cmd = "net user " + string(username) + " /times:";
    for (size_t i = 0; i < dienos.size(); i++) {
        cmd += dienos[i] + "," + valandos;
        if (i != dienos.size() - 1) {
            cmd += ";";
        }
    }

    vykdyti_cmd(cmd.c_str());

    return 0;
}
void ping(const char* adresas) {
    string failas = "ping_output.txt";
    string komanda = "ping " + string(adresas) + " > " + failas;
    system(komanda.c_str());

    ifstream F(failas);
    string eilute;
    while (getline(F, eilute)) {
        cout << eilute << endl;
    }
    F.close();
    system(("del " + failas).c_str());
}

void atidaryti_valdymo_skyda(int komponentasnr) {
    string komanda;
    switch (komponentasnr) {
    case 1: komanda = "start ms-settings:display"; break;
    case 2: komanda = "start ms-settings:windowsdefender"; break;
    case 3: komanda = "start ms-settings:powersleep"; break;
    case 4: komanda = "start ms-settings:storagesense"; break;
    case 5: komanda = "start ms-settings:windowsupdate"; break;
    default:
        cout << "Neteisingas pasirinkimas" << endl;
        return;
    }
    vykdyti_cmd(komanda.c_str());
}

void kurti_folder() {
    string pavarde = "Podgaiska";
    string vardas = "Paulina";

    char* userProfile = nullptr;
    size_t len;
    _dupenv_s(&userProfile, &len, "USERPROFILE");

    if (userProfile == nullptr) {
        cerr << "Klaida: nepavyko gauti vartotojo profilio aplanko!" << endl;
        return;
    }

    string pagrindinis_kelias = string(userProfile) + "\\Documents\\" + pavarde;
    free(userProfile);  

    if (_mkdir(pagrindinis_kelias.c_str()) == 0) {
        cout << "Sukurtas aplankas: " << pagrindinis_kelias << endl;
    }
    else {
        cout << "Aplankas jau egzistuoja: " << pagrindinis_kelias << endl;
    }

    for (int i = 1; i <= 3; i++) {
        string dir1 = pagrindinis_kelias + "\\" + vardas + to_string(i);

        if (_mkdir(dir1.c_str()) == 0) {
            cout << "Sukurtas aplankas: " << dir1 << endl;
        }
        else {
            cout << "Aplankas jau egzistuoja: " << dir1 << endl;
        }

        for (int j = 1; j <= 3; j++) {
            string dir2 = dir1 + "\\Paulinos" + to_string(i) + vardas + to_string(j);

            if (_mkdir(dir2.c_str()) == 0) {
                cout << "Sukurtas aplankas: " << dir2 << endl;
            }
            else {
                cout << "Aplankas jau egzistuoja: " << dir2 << endl;
            }
        }
    }
}

void kilpa(double F, double x0, double xn, double dx, const char* failaiF) {
    char* userProfile = nullptr;
    size_t len;
    _dupenv_s(&userProfile, &len, "USERPROFILE");
    string dokumentai = string(userProfile) + "\\Documents\\";
    string basepath = dokumentai + "Podgaiska";
    free(userProfile);
    string failasF = failaiF;
    const int foldersk = 9;
    std::array<std::string, foldersk> folderpath = {
        basepath + "\\Paulina1\\Paulinos1Paulina1\\" + failasF,
        basepath + "\\Paulina1\\Paulinos1Paulina2\\" + failasF,
        basepath + "\\Paulina1\\Paulinos1Paulina3\\" + failasF,
        basepath + "\\Paulina2\\Paulinos2Paulina1\\" + failasF,
        basepath + "\\Paulina2\\Paulinos2Paulina2\\" + failasF,
        basepath + "\\Paulina2\\Paulinos2Paulina2\\" + failasF,
        basepath + "\\Paulina3\\Paulinos3Paulina1\\" + failasF,
        basepath + "\\Paulina3\\Paulinos3Paulina2\\" + failasF,
        basepath + "\\Paulina3\\Paulinos3Paulina3\\" + failasF,
    };
    array<ofstream, foldersk> files;
    for (int i = 0; i < foldersk; i++) {
        files[i].open(folderpath[i], ios::app);
    }

    int dabartinisfolder = 0;
    for (double x = x0; x <= xn; x += dx) {
        double y2 = pow(x, 3) + 3 * pow(x, 2) - F;
        if (y2 < 0) continue;

        double y = sqrt(y2);
        files[dabartinisfolder] << x << " " << y << endl;
        dabartinisfolder = (dabartinisfolder + 1) % foldersk;

        if (y != 0.0) {
            double yneig = -y;
            files[dabartinisfolder] << x << " " << yneig << endl;
            dabartinisfolder = (dabartinisfolder + 1) % foldersk;
        }
    }

    for (auto& out : files) out.close();
}

void sulieti_failus(const char* failopav) {
    char* userProfile = nullptr;
    size_t len;
    _dupenv_s(&userProfile, &len, "USERPROFILE");
    string dokumentai = string(userProfile) + "\\Documents\\";
    free(userProfile);

    string naujas_kelias = dokumentai + "naujas";
    _mkdir(naujas_kelias.c_str());
    string sujungimo_failas = naujas_kelias + "\\sujungti_duomenys_" + failopav;

    vector<pair<double, double>> duomenys;
    string basepath = dokumentai + "Podgaiska";
    const int foldersk = 9;
    string folderpath[foldersk] = {
        basepath + "\\Paulina1\\Paulinos1Paulina1\\" + failopav,
        basepath + "\\Paulina1\\Paulinos1Paulina2\\" + failopav,
        basepath + "\\Paulina1\\Paulinos1Paulina3\\" + failopav,
        basepath + "\\Paulina2\\Paulinos2Paulina1\\" + failopav,
        basepath + "\\Paulina2\\Paulinos2Paulina2\\" + failopav,
        basepath + "\\Paulina2\\Paulinos2Paulina2\\" + failopav,
        basepath + "\\Paulina3\\Paulinos3Paulina1\\" + failopav,
        basepath + "\\Paulina3\\Paulinos3Paulina2\\" + failopav,
        basepath + "\\Paulina3\\Paulinos3Paulina3\\" + failopav,
    };

    for (int i = 0; i < foldersk; i++) {
        ifstream infile(folderpath[i]);
        if (!infile) continue;

        double x, y;
        while (infile >> x >> y) {
            duomenys.push_back({ x, y });
        }
        infile.close();
    }

    sort(duomenys.begin(), duomenys.end());
    ofstream outfile(sujungimo_failas);
    for (const auto& pair : duomenys) {
        outfile << pair.first << " " << pair.second << endl;
    }
    outfile.close();
}

void istrinti_folder() {
    string kelias = "\"%USERPROFILE%\\Documents\\Podgaiska\"";
    string cmd = "rmdir /s /q " + kelias;
    system(cmd.c_str());
}