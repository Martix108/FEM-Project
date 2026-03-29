#pragma once
#include "GaussP.h"
#include "Functions.h"

template <typename GaussType>
double GaussQuad1D(double (*f)(double), const GaussType& gauss) {
	double suma = 0.0;

	for (int i = 0; i < gauss.nodes.size(); i++) {
		suma += gauss.coefficients[i] * f(gauss.nodes[i]);
	}

	return suma;
}

template <typename GaussType>
double GaussQuad2D(double (*f)(double, double), const GaussType& gauss) {
	double suma = 0.0;

	for (int i = 0; i < gauss.nodes.size(); i++) {
		for (int j = 0; j < gauss.nodes.size(); j++) {
			suma += gauss.coefficients[i] * gauss.coefficients[j] * f(gauss.nodes[i], gauss.nodes[j]);
		}
	}

	return suma;
}