#pragma once

#ifndef __KNN_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <random>
#include <cstdlib> 

namespace KNN {
	
	std::vector <std::vector<double>> generate_random_hyperplanes(int num_feats, int hps);
}

#endif // !__KNN_H_

