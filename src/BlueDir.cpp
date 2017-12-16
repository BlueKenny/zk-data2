#include <string>
using namespace std;

#include <sys/stat.h>
#include <sys/types.h>

#include <iostream>

#include <dirent.h> 
#include <stdio.h> 

#include <vector>

struct stat st;

extern bool PathExists(std::string directory){
	if (stat(directory.c_str(),&st) == 0) {
		return true;
	 }
	else {
		return false;
	}
	
}

extern void MkDir(std::string directory){ // MkDir if not exists
	if (!PathExists(directory)){
		mkdir(directory.c_str(), 0777);
		cout << "mkdir \"" << directory << "\"" << endl;
	}
	
	//int status;
	//status = mkdir(directory, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	/*	
	boost::filesystem::path dir(directory);
	;
	if(boost::filesystem::create_directory(dir){
		cout << "ok" << endl;
	}
	else {
		cout << "no" << endl;
	}*/
	return;
}
extern std::string ListDir(std::string directory){
	//cout << "mkdir" << endl;
	std::string OUTPUT = {};

	DIR           *d;
	struct dirent *dir;
	
	d = opendir(directory.c_str());
	if (d){
		while ((dir = readdir(d)) != NULL){
			std::string DIRNAME = dir ->d_name;
			if (DIRNAME != "." and DIRNAME != ".."){
				//cout << "\"" << DIRNAME << "\"" << endl;
				list.push_back(DIRNAME);
			}
		}
		closedir(d);
	}

	return;
}

