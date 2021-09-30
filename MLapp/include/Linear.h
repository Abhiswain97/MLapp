#pragma once

#ifndef _LINEAR_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <random>
#include <cstdlib> 
#include <Utils.h>

class LinearModels {

public:
	std::vector<std::vector<double>> X;
	std::vector<double> wt;
	std::vector<double> y;
	/*
	* Constructor to initialize Linear models
	**/
	LinearModels(std::vector<std::vector<double>> X, std::vector<double> y)
		: X(X), y(y) {}
	
	/*
	* Intialize weight vector based on dimensions
	**/
	void initialize_weight_bias(int dims);

	double sigmoid(double z);

	std::vector<std::vector<double>> make_preds();

	void StandardScaler();

};



#endif // !_LINEAR_H_
