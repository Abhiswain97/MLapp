#include "Utils.h"

std::map<std::string, int> utils::make_count_map(std::string& sentence) {
	std::map<std::string, int> count_map;
	std::vector<std::string> tokens = tokenize(sentence, ' ');
	for (auto& word : tokens) {
		if (!count_map.count(word))
			count_map[word] = 1;
		else
			count_map[word]++;
	}

	return count_map;
}

std::vector<std::string> utils::tokenize(std::string& str, char delimiter) {
	std::vector<std::string> tokens;

	std::stringstream sen(str);
	std::string intermediate;

	while (std::getline(sen, intermediate, delimiter)) tokens.push_back(intermediate);

	return tokens;
}

std::vector<std::string> utils::unique_words(std::vector<std::string>& corpus) {
	std::set<std::string> words;
	std::vector<std::string> unq_wrds;

	for (auto& sentence : corpus) {
		std::vector<std::string> tokens = tokenize(sentence, ' ');
		std::for_each(tokens.begin(), tokens.end(),
			[&](auto s) { words.insert(s); });
	}

	for (auto& word : words) {
		unq_wrds.push_back(word);
	}

	return unq_wrds;
}

/*
* Modified from : http://inversionlabs.com/2015/10/30/vector-printing-template.html
*/
template <typename T>
std::string utils::print_vector(const T& vector) {
	std::string s;

	s += "\n";
	s += "{";

	for (auto& row : vector) {
		for (auto& element : row) {
			std::ostringstream ss;
			ss << std::fixed << std::setprecision(2);
			ss << element;
			s += ss.str();
			s += ", ";
		}
		s += "\n";
	}

	// clear the trailing comma, space
	if(s.size() >= 2) s.erase(s.size() - 3);
	
	s += "}";
	s += "\n";

	return s;
}
 
void utils::print(std::vector<std::string>& vec) {
	for (auto&& v1 : vec) {
		for (auto&& i : v1) {
			std::cout << i;
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<double>> utils::transpose(std::vector<std::vector<double>>& vector) {
	std::vector<std::vector<double>> transposed_vector(vector[0].size(), std::vector<double>());

	for (size_t i = 0; i < vector.size(); i++)
		for (size_t j = 0; j < vector[i].size(); j++)
			transposed_vector[j].push_back(vector[i][j]);

	return transposed_vector;
}

utils::csv_details utils::read_csv(std::string& filename) {
	std::ifstream ifs(filename);

	std::string line, columns;

	std::getline(ifs, columns);

	std::vector<std::string> lines;

	while (std::getline(ifs, line))
		lines.push_back(line);

	utils::csv_details csv_details;

	csv_details.columns = columns;
	csv_details.lines = lines;

	return csv_details;
}


double utils::round_upto(double num, int k) {

	int approx = pow(10, k);

	double value = (int)(num * approx + .5);

	return (double)value / approx;
}