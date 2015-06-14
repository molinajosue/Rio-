#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Read_Number_of_Samples.h"
#include "Log_Likelihood_Fitter.h"

using namespace std;

int main(int argc,char *argv[]){
   	
	cout << "###################################################" << endl;
	cout << "#                                                 #" << endl;
	cout << "#         Welcome to Log_Likelihood_Fitter        #" << endl;
	cout << "#                                                 #" << endl;
	cout << "#                                                 #" << endl;
	cout << "#       Authors: Sandra Amato, Rafael Aoude       #" << endl;
	cout << "#   Carla Gobel, Josue Molina, Érica Polycarpo, #" << endl;
	cout << "#         Alberto Reis, Danielle Tostes,          #" << endl;   
	cout << "#                and Daniel Vieira                #" << endl;
	cout << "#                                                 #" << endl;
	cout << "#            contact: dvieira@if.ufrj.br          #" << endl;
	cout << "#                                                 #" << endl;
	cout << "#                    Have fun!                    #" << endl;
	cout << "#                                                 #" << endl;
	cout << "###################################################" << endl;
	cout << endl;
//////////////////////////////
    if ( argc !=2 ) {
        return EXIT_FAILURE;
    }
//////////////////////////////
    
    string string=argv[1];
    int number_of_samples;

    cout << "Reading input file name:" << string<< endl;
    Read_Number_of_Samples(string, number_of_samples);
  
    ostringstream oss2;
    oss2 << "fitparameters_" << string.c_str();
    ofstream myfile;  //file to output the fit result - ofstream : Stream class to write on files
    myfile.open (oss2.str().c_str(),ios::out); //ios:out :  opens file for writing
    myfile.close();
 
 for ( int sample_number = 0; sample_number<number_of_samples; ++sample_number ){
       Log_Likelihood_Fitter(string, sample_number);
    }
    
	return 0;
}

