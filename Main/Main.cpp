#include "MLapp.h"
#include "../src/Utils.cpp"


int main(int argc, char const* argv[]) {
    std::vector<std::string> corpus = {
		"this is the first document",
		"this is the second document"
	};

    std::vector<double> y = { 1, 0 };

    BOW tfidf(corpus);

    auto vector = tfidf.fit();

    LinearModels lin(vector, y);

    std::cout << utils::print_vector(vector);

    std::string fname = "C:\\Users\\abhi0\\Desktop\\MLapp\\MLapp\\data\\Housing.csv";

    auto lines = utils::read_csv(fname);
    auto columns = utils::tokenize(lines.columns, ',');

    auto tok = utils::tokenize(fname, '\\');
    
    std::cout << "The Columns are: \n";

    std::cout << columns[1] << " " << columns[2] << "\n";

    auto hps = KNN::generate_random_hyperplanes(4, 5);

    std::cout << utils::print_vector(hps);

    /*
    for (auto& line : lines.first)
    {
        auto tokens = utils::tokenize(line, ',');
        std::cout << tokens[1] << " " << tokens[2] << "\n";
    }
    */

    // lin.StandardScaler();

    return 0;
}