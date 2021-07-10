#include "MLapp.h"

using pred_probs = std::pair<std::vector<int>, std::vector<double>>;

pred_probs dummy_model(std::vector<std::vector<double>>& X_train,
    std::vector<int>& y_train) {
    double sum = 0.0, avg = 0.0;
    std::vector<int> y_pred;
    std::vector<double> y_probs;

    for (auto& feature : X_train) {
        std::for_each(feature.begin(), feature.end(),
            [&](double f) -> void { sum += f; });
        avg = sum / (double)feature.size();

        y_probs.push_back(avg);

        if (avg < 0.5)
            y_pred.push_back(0);
        else
            y_pred.push_back(1);
    }

    return std::make_pair(y_pred, y_probs);
}

int main(int argc, char const* argv[]) {
    std::vector<std::string> corpus = {
		"this is the first document",
		"this is the second document"
	};
    
    Tfidf tfidf(corpus);
    BOW bow(corpus);

    auto vector = bow.fit();

    bow.print_vector(vector);
    
    return 0;
}