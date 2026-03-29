#include <iostream>
#include <cstdio>
#include "Functions.h"
#include "GaussP.h"
#include "GaussQuad.h"
#include "Grid.h"
#include "Structs.h"
#include "FileGenerator.h"
using namespace std;


int main() {
	GlobalData global;								//Dane globalne
	grid g;											//Siatka Grid
	Gauss2P gaussP;									//Dobór Gaussa x punktowego
	global.nPC = pow(gaussP.nodes.size(), 2);		//Liczba punktów całkowania

	//Wczytywanie danych z pliku
	if (!loadGridData("../Siatka_Cegla_duza.txt", global, g)) {		//Test1_4_4.txt		Test2_4_4_MixGrid.txt	Test3_31_31_kwadrat.txt		Siatka_Cegla_duza.txt
		return 1;
	}
	
	//Zmienne potrzebne do pracy na Elementach Uniwersalnych i macierzach globalnych
	ElemUniv EU(global.nPC);
	SystemOfEquation SOE(global.nN);

	//Dane potrzebne do zapisu do pliku
	vector<string> vtuFiles;
	vector<double> timesteps;
	bool firstStep = true;
	
	
	
	//cout << "Macierz t (step 0):" << endl;
	for (int i = 0; i < g.nN; ++i) {
		SOE.t[i] = global.InitialTemp;
		//cout << SOE.t[i] << " ";
	}
	//cout << endl << endl;
	
	
	//global.SimulationStepTime = 55; //Minimalna wartość dla mixGrid żeby obliczenia miały sens
	for (int step = global.SimulationStepTime; step <= global.SimulationTime; step += global.SimulationStepTime)
	{
		calculate_dN_dKsi(EU, gaussP);
		calculate_dN_dEta(EU, gaussP);
		calculateN(EU, gaussP);
		calculateSurfaceN(EU, gaussP);
		
		for (int i = 0; i < g.element.size(); i++) {
			element& el = g.element[i];
			calculateData(global.nPC, g, el, EU);

			calculateH(el, global, gaussP);
			calculateHbc(el, g, global, EU, gaussP);
			calculateP(el, g, global, EU, gaussP);
			calculateC(el, EU, global, gaussP);
			
			calculateHGlobal(el, SOE);
			calculatePGlobal(el, SOE);
			calculateCGlobal(el, SOE);
		}
		
		solve_time(SOE, global);

		string filename = "result_step_" + to_string(step) + ".vtu";
		writeVTU(filename, g, SOE);
		vtuFiles.push_back(filename);
		timesteps.push_back(step);

		writeTemperatureMinMax("temperature_min_max.txt", SOE.t, step, firstStep);
		firstStep = false;


		//Wypisanie wyników
		cout << "Macierz t (step " << step << "):" << endl;
		for (int i = 0; i < g.nN; i++) {
			cout << SOE.t[i] << " ";
		}
		cout << endl << endl;		
		
	}
	
	writePVD("results.pvd", vtuFiles, timesteps);
	
	
	return 0;
}