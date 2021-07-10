#include "Tfidf.h"


int main() {
	std::vector<std::string> corpus = {
		"this is the first document",
		"this is the second document"
	};

	Tfidf tfidf(corpus);

	auto vector = tfidf.fit();

	tfidf.print_vector(vector);

	std::cin.get();
}