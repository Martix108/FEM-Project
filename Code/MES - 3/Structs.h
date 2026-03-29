#pragma once
#include <vector>
#include <string>
#include "GaussP.h"

struct ElemUniv {
	struct Surface {
		std::vector<std::vector<double>> N;
	};
	
	std::vector<std::vector<double>> dN_dKsi;		//ξ
	std::vector<std::vector<double>> dN_dEta;		//η
	std::vector<std::vector<double>> N;
	std::vector<Surface> surface;
	ElemUniv(int nPC = 0);
};

struct Jakobian {
	std::vector<std::vector<double>> J;
	std::vector<std::vector<double>> J1;
	double detJ = 0.0;
	Jakobian();
};

struct DN_dx_dy {
	std::vector<double> dN_dx;
	std::vector<double> dN_dy;
};

struct node {
	double x, y;
	bool BC;
};

struct element {
	int globalID;
	std::vector<int> ID;
	std::vector<Jakobian> jakobian;
	std::vector<DN_dx_dy> dN_dx_dy;
	std::vector<std::vector<double>> H;
	std::vector<std::vector<double>> Hbc;
	std::vector<double> P;
	std::vector<std::vector<double>> C;
	element(int nPC = 0);
};

struct grid {
	int nN = 0, nE = 0;
	std::vector<node> node;
	std::vector<element> element;
};

struct SystemOfEquation {
	std::vector<std::vector<double>> Hg;
	std::vector<std::vector<double>> Cg;
	std::vector<double> Pg;
	std::vector<double> t;
	SystemOfEquation(int nN = 0);
};

struct GlobalData {
	double SimulationTime, SimulationStepTime, Conductivity, Alfa, Tot,
		InitialTemp, Density, SpecificHeat;
	int nN, nE, nPC;
};


element::element(int nPC) {
	jakobian.resize(nPC);
	dN_dx_dy.resize(nPC);
	H.assign(4, std::vector<double>(4, 0.0));
	Hbc.assign(4, std::vector<double>(4, 0.0));
	C.assign(4, std::vector<double>(4, 0.0));
	P.assign(4, 0.0);
	globalID = 0;
}

ElemUniv::ElemUniv(int nPC) {
	dN_dKsi.resize(nPC, std::vector<double>(4, 0.0));
	dN_dEta.resize(nPC, std::vector<double>(4, 0.0));
	N.resize(nPC, std::vector<double>(4, 0.0));
	surface.resize(4);

	for (int i = 0; i < 4; i++) {
		surface[i].N.resize(nPC, std::vector<double>(4, 0.0));
	}
}

Jakobian::Jakobian() {
	J.resize(2, std::vector<double>(2, 0.0));
	J1.resize(2, std::vector<double>(2, 0.0));
}

SystemOfEquation::SystemOfEquation(int nN) {
	Hg.resize(nN, std::vector<double>(nN, 0.0));
	Cg.resize(nN, std::vector<double>(nN, 0.0));
	Pg.resize(nN, 0.0);
	t.resize(nN, 0.0);
}