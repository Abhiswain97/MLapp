#include "MLapp.h"
#include "../src/Utils.cpp"
#include <Eigen/Dense>

using namespace Eigen;

int main(int argc, char const* argv[]) {

    Matrix<float, 3, 3> mat1;

    mat1.setZero();

    MatrixXd mat2(2, 2);
    
    mat2 << 1, 2,
        3, 4;

    std::cout << mat2 << std::endl;
    std::cout << mat1;

    std::vector<std::string> corpus = {
		"this is the first document",
		"this is the second document"
	};

    std::vector<double> y = { 1, 0 };

    BOW tfidf(corpus);

    auto vector = tfidf.fit();

    std::cout << utils::print_vector(vector);

    LinearModels lin(vector, y);

    std::cout << utils::print_vector(vector);

    std::string fname = "C:\\Users\\abhis\\repos\\MLapp\\MLapp\\data\\Housing.csv";

    auto lines = utils::read_csv(fname);
    auto columns = utils::tokenize(lines.columns, ',');

    auto tok = utils::tokenize(fname, '\\');

    for (auto &col : columns) {
        std::cout << col << ",";
    }

    std::cout << "\n";
 
    for (auto &line : lines.lines) {
        auto tok_line = utils::tokenize(line, ',');
        for (auto& item : tok_line) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }

    auto hps = KNN::generate_random_hyperplanes(4, 5);

    std::cout << utils::print_vector(hps);

    /*for (auto& line : lines.first)
    {
        auto tokens = utils::tokenize(line, ',');
        std::cout << tokens[1] << " " << tokens[2] << "\n";
    }*/
    

    lin.StandardScaler();

    return 0;
}