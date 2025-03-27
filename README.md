# Programa su mano DLL
Programa kuriama „Microsoft Visual Studio 2022“ aplinkoje. Čia yra sukuriamas projektas 
„MyDLLandAPPandSetup“, kuriame pridedamas „Dll.h“ failas, „dllmain.cpp“, „AppWithDll.cpp“.
„dllmain.cpp“ faile yra aprašytos funkcijos, kurios bus naudojamos mūsų programos „AppWithDll.cpp“, o „Dll.h“ faile deklaruojamos visos „dllmain.cpp“ funkcijos. Programoje įgyvendintos laiko matavimo funkcija, darbo laiko prie kompiuterio pasirinktam vartotojui apribojimas, naujų aplankalų kūrimas (Podgaiska), Tšrinhauseno kilpos skaičiavimas ir rastų taškų rašymas cikliškai į tekstinius failus, failų suliejimo funkciją pagal atitinkamą F ir Podgaiska aplankalo trinimo funkciją. Šie aplankalai yra kuriami keliu: C:\%USERPROFILE%\Documents\Podgaiska. Taip pat programa apskaičiuoja Tšrinhauseno kilpą, kurios funkcija yra F=x3+3x2-y2, čia F yra žinomi ir bus paduodami funkcijai: F= -2 , F= -1, F= 0, F=1, F=2, o x yra intervale nuo [-studento_id%19;studento_id%25], žingsniu (studento_id/1012). Taškai, t.y. X,Y pora yra įrašoma į failus po vieną į skirtngus failus skirtinguose aplankaluose. Funkcija yra skaičiuojama tik taškuose, kuriuose ji egzistuoja. Paleidus programą vartotojas mato tokį langą, kuriame programa praso vartotojo atlikti tam tikrus veiksmus. Programos pradžios veiksmų pasirinkimas :
Pasirinkus 1- norime testi, toliau galima pasirinkti ar norime blokuoti laiką ar ne, atitinkamai paspaudus 1 arba 
2. Pasirinkus 1, programa prašo įvesti vartotojo vardą, kuriam norime blokuoti laiką, įvesti 
savaitės dienų skaičių, kuriomis laikas bus blokuojamas ir blokuojamas valandas (formatu 00:00
23:59), toliau iš sąrašo pasirinkti savaitės dienas. Norint atlikti darbo laiko prie kompiuterio blokavimą reikės sutikti, kad bus atlikti tam tikri pakeitimai, kuriem reikalaujamos administravimo teises. 
Atlikus kilpos skaiciavimus, sulieti tekstiniai failai pagal atitinkamą F per „File Explorer“ turetu atrodyti taip:

![image](https://github.com/user-attachments/assets/bd268b8f-18be-4fc2-aa63-bc3f41af17d3)

Programa baigus skaičiuoti pateikia galutinai sugaištą laiką minutėmis.

# Diegiklio kūrimas

Visų pirmą „Microsoft Visual Studio“ sukuriame Setup projektą „ProgramInstallSetup“, kur pažymime, kad jis būtų pridėtas prie egzistuojančio sprendimo. Prie Setup projekto pridedame projekto išvestį, naudojančią mūsų programą su DLL „AppWithDLL“ ir taip pat su „Dll“. Sukuriame „Program Menu“ aplankalą su nuoroda į mūsų programos paleidžiamąjį failą. Sukurtą nuorodą iškerpama iš „Application Folder“ ir įkeliama į „User‘s Programs Menu“ ir „User‘s Desktop“. Sutvarkius vedlio projekto nustatymus jį kompiliuojame ir projekto aplankale, kur yra mūsų „ProgramInstallSetup“ atsiranda du failai „ProgramInstallSetup.msi“ ir „setup.exe“. 
Paleidus „ProgramInstallSetup.msi“ vedlį ir parsisiuntus programą pagal nurodytą kelią, (by default „C:Program Files\VilniausUniversitetas\ProgramInstallSetup“) randame programos paleidžiamąjį failą „AppWithDll.exe“. Mano programa atsiranda tiek „Start Menu“, tiek „Desktop“. Programą galima paleisti iš aplankalo, esančio „Program Files“, „Start Meniu“ arba „Desktop“ shortcuto. 
