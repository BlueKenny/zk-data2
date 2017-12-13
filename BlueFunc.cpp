#include <string>
#include "BlueDir.h"

#include <iostream>
//#include <iterator>
#include <fstream>
#include <vector>
//#include <algorithm>

std::string SplitIt = "&zKz&";

extern std::string BlueLoad(std::string VarName, std::string FileDir){
	std::string output;

	if (PathExists(FileDir)){
		std::ifstream filestream(FileDir);
		std::string line;
		

		while(std::getline(filestream, line))
		{
			//std::cout << "Read this line : " << line << std::endl;
			if (line.find(VarName + SplitIt) != std::string::npos && line.find(VarName + SplitIt) == 0){// if [VarName + "&zKz&"] in line AND startswith it
				std::string output = line.erase(0, VarName.length() + SplitIt.length());
				return output;
			}
		}
	}
	else {
		return "None";
	}
	return output;
}

/*

SplitIt = "&zKz&"
def BlueLoad(VarName, File):
	if os.path.exists(File): //
		Datei = open(File, "r", errors="ignore")
		DateiDatenIndex = Datei.readlines()
		Datei.close()
		Gefunden=False
		for AlleLinien in DateiDatenIndex:
			LinienVarName = AlleLinien.split(SplitIt)[0]
			if VarName == LinienVarName:	
				SavedData = AlleLinien.split(SplitIt)[1].rstrip()
				return SavedData

def BlueSave(VarName, VarData, File):
	if os.path.exists(File): 
		Datei = open(File, "r", errors="ignore")
		DateiDatenIndex = Datei.readlines()
		Datei.close()
		Gefunden=False
		for AlleLinien in DateiDatenIndex:
			LinienVarName = AlleLinien.split(SplitIt)[0]
			if VarName == LinienVarName:	
				Gefunden=True
				LinienVarData = AlleLinien.split(SplitIt)[1]

				Datei = open(File, "r", errors="ignore")
				DateiDaten = Datei.read()
				Datei.close()

				Datei = open(File, "w")
				Datei.write(DateiDaten.replace(str(LinienVarName) + str(SplitIt) + str(LinienVarData), str(VarName) + str(SplitIt) + str(VarData) + "\n"))
				Datei.close()
		if not Gefunden:
			Datei = open(File, "a")
			Datei.write("\n" + str(VarName) + str(SplitIt) + str(VarData))
			Datei.close()
	else:
		Datei = open(File, "w")
		Datei.write(str(VarName) + str(SplitIt) + str(VarData))
*/
