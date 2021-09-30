#include <Linear.h>

void LinearModels::initialize_weight_bias(int dims) {
	for (size_t i = 0; i < dims; i++)
		this->wt.push_back(0);
}

void LinearModels::StandardScaler() {
	for (size_t row = 0; row < this->X.size(); row++)
	{
		double sum = 0.0;
		sum = std::accumulate(this->X[row].begin(), this->X[row].end(), sum);

		std::cout << sum / this->X.size() << " ";
	}

	//utils::print_vector(this->X);
}

double LinearModels::sigmoid(double z) {
	return 1 / (1 + exp(-1 * z));
}







