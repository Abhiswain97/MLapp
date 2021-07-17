#include "MLapp.h"

int main(int argc, char const* argv[]) {
    std::vector<std::string> corpus = {
		"this is the first document",
		"this is the second document"
	};

    std::vector<double> y = { 1, 0 };

    Tfidf tfidf(corpus);

    auto vector = tfidf.fit();

    LinearModels lin(vector, y);

    lin.initialize_weight_vector();

    utils::print_vector(lin.wt);

    auto t_vec = utils::transpose(vector);

    auto res = lin.make_preds();

    utils::print_vector(res);

    return 0;
}