#include <KNN.h>
#include <Utils.h>

std::vector <std::vector<double>> KNN::generate_random_hyperplanes(int num_feats, int hps) {
	
	srand(time(0));

	std::vector <std::vector<double>> hyperplanes;

	for (size_t i = 0; i < hps; i++)
	{
		std::vector<double> temp;
		for (size_t j = 0; j < num_feats; j++) {
			double val = utils::round_upto((double)rand() / RAND_MAX, 3);
			temp.emplace_back(val);
		}

		hyperplanes.push_back(temp);
	}

	return hyperplanes;
}