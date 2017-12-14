
#include <string>
using namespace std;

#include <iostream>

#include "BlueInt.h"

extern std::string Date() { // print Date [ 2017-12-10 ]
	time_t Zeitstempel;
	tm *nun;
	Zeitstempel = time(0);
	nun = localtime(&Zeitstempel);

	string JAHR = IntToString(nun->tm_year+1900);
	string MONAT = IntToString(nun->tm_mon+1);
	string TAG = IntToString(nun->tm_mday);

	string DATUM = JAHR + "-" + MONAT + "-" + TAG;

	return DATUM;
}

extern int TageSeit1944(int STARTJAHR, int STARTMONAT, int STARTTAG) { // Get Days since (YYYY, M, D)
	

	int DifJahr = STARTJAHR - 1944;
	int DifMonat = STARTMONAT - 1;
	int DifTag = STARTTAG - 1;

	int TestJahr = 1944;
	int TestMonat = 1;

	int TAGE = 0;//Ergebnis
	int ADDTAGE = 0;//So viele Tage werden hinzugefuegt

	int SchaltJahre[20] = {1944, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020};
	int MonateMit30Tagen[4] = {4, 6, 9, 11};
	int MonateMit31Tagen[7] = {1, 3, 5, 7, 8, 10, 12};
	
	if (DifJahr > 0){
		//cout << "DifJahr " << DifJahr << endl;
		while(TestJahr < STARTJAHR){
			//cout << "TestJahr " << TestJahr << endl;
			ADDTAGE = 365;
			for (int i=0; i<20; i++) {
				//cout << "SchaltJahre[" << i << "] = " << SchaltJahre[i] << endl;
				if (SchaltJahre[i] == TestJahr){
					ADDTAGE = 366;
					break;
				}
			}
			//cout << "Das Jahr " << TestJahr << " hat " << ADDTAGE << " tage" << endl;
			TAGE += ADDTAGE;
			TestJahr += 1;
		}
	}
	if (DifMonat > 0){
		//cout << "DifMonat " << DifMonat << endl;
		while(TestMonat < STARTMONAT){
			//cout << "TestMonat " << TestMonat << endl;
			for (int i=0; i<4; i++) {
				//cout << "MonateMit30Tagen[" << i << "] = " << MonateMit30Tagen[i] << endl;
				if (MonateMit30Tagen[i] == TestMonat){
					ADDTAGE = 30;
					break;
				}
			}
			for (int i=0; i<7; i++) {
				//cout << "MonateMit31Tagen[" << i << "] = " << MonateMit31Tagen[i] << endl;
				if (MonateMit31Tagen[i] == TestMonat){
					ADDTAGE = 31;
					break;
				}
			}
			if (TestMonat == 2){
				ADDTAGE = 28;
				for (int i=0; i<20; i++) {
					if (SchaltJahre[i] == STARTJAHR){
						ADDTAGE = 29;
						break;
					}
			}
			}
			//cout << "Der Monat " << TestMonat << " hat " << ADDTAGE << " tage" << endl;
			TAGE += ADDTAGE;
			TestMonat += 1;
			
		}
	}
	if (DifTag > 0){
		cout << "DifTag " << DifTag << endl;
		TAGE += DifTag;

	}
	

	return TAGE;
}

extern int ElapsedDays(int STARTJAHR, int STARTMONAT, int STARTTAG) {
	time_t Zeitstempel;
	tm *nun;
	Zeitstempel = time(0);
	nun = localtime(&Zeitstempel);

	int JAHR = nun->tm_year+1900;
	int MONAT = nun->tm_mon+1;
	int TAG = nun->tm_mday;

	int TageSeit1944BisStart = TageSeit1944(STARTJAHR,STARTMONAT,STARTTAG);
	int TageSeit1944BisHeute = TageSeit1944(JAHR,MONAT,TAG);
	return TageSeit1944BisHeute - TageSeit1944BisStart;
}
