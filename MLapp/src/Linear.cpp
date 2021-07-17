#include <Linear.h>

void LinearModels::initialize_weight_vector() {
	
	for (size_t i = 0; i < this->X.size(); i++){
		std::vector<double> temp;
		for (size_t j = 0; j < this->X[0].size(); j++){
			auto n = static_cast<double> (rand()) / RAND_MAX;
			temp.push_back(n);
		}
		this->wt.push_back(temp);
	}
}

double LinearModels::sigmoid(double z) {
	return 1 / (1 + exp(-1 * z));
}

std::vector<std::vector<double>> LinearModels::make_preds() {
	auto wt_T = utils::transpose(this->wt);
	std::vector<std::vector<double>> res;
	
	for (size_t i = 0; i < this->X.size(); i++) {
		std::vector<double> temp;
		for (size_t j = 0; j < this->X[i].size(); j++)
			temp.push_back(wt_T[j][i] * X[i][j]);
		res.push_back(temp);
	}

	for (size_t i = 0; i < res.size(); i++) {
		for (size_t j = 0; j < res[i].size(); j++)
			std::cout << this->sigmoid(res[i][j]) << " ";
		std::cout << "\n";
	}

	return res;
}








