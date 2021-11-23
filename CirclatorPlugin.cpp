#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "CirclatorPlugin.h"

void CirclatorPlugin::input(std::string file) {
 inputfile = file;
 std::cout << inputfile << std::endl;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   std::cout << key << std::endl;
   if (key.size() != 0)
   parameters[key] = value;
   else
	   break;
 }

}

void CirclatorPlugin::run() {
}


void CirclatorPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 //std::string outdirname = file.substr(file.find_last_of("/")+1);
 //std::string outpath = file.substr(0, file.find_last_of("/"));
//circlator all Assembly.fasta short_reads_together.fa Circlator_output
myCommand += "rm -r "+outputfile+"; circlator all "+std::string(PluginManager::prefix())+"/"+parameters["fastafile"]+" "+std::string(PluginManager::prefix())+"/"+parameters["reads"]+" "+outputfile+"; cp "+outputfile+"/06.fixstart.fasta "+outputfile+"/../";
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<CirclatorPlugin> CirclatorPluginProxy = PluginProxy<CirclatorPlugin>("Circlator", PluginManager::getInstance());
