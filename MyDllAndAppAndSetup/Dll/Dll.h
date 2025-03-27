#pragma once
#ifndef _DLL_H_
#define _DLL_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <direct.h> 
#include <thread>
#include <mutex>
#include <chrono>
#include <sys/stat.h>
#include <sstream>
#include <ctime>
#include <cmath>
#include <array>
#ifdef DLL_EXPORTS
#define DLL_API _declspec(dllexport)
#else
#define DLL_API _declspec(dllimport)
#endif

using std::cout;
using std::endl;
using std::wcout;
using std::wstring;
using namespace std::chrono;
extern std::mutex failu_mutex;

extern "C" {

    DLL_API void vykdyti_cmd(const char* komanda);

    DLL_API void pradeti_laikma();

    DLL_API double gauti_vykdymo_laika();

    DLL_API int apribojimas(const char* username, int kiek, const char* valandos);

    DLL_API void ping(const char* adresas);

    DLL_API void atidaryti_valdymo_skyda(int komponentasnr);

    DLL_API void kurti_folder();

    DLL_API void kilpa(double F, double x0, double xn, double dx, const char* failaiF);
  
    DLL_API void sulieti_failus(const char* failopav);

    DLL_API void istrinti_folder();
}


#endif


