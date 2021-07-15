#include "Preprocess.h"

std::map<std::string, std::vector<int>> Preprocess::one_hot_encode() {
    std::map<std::string, std::vector<int>> encoded_dict;

    int i = 0;

    std::for_each(this->labels.begin(), this->labels.end(),
        [&](std::string label) -> void {
            std::vector<int> vec(this->labels.size(), 0);

            vec[i++] = 1;

            encoded_dict[label] = vec;
        });

    return encoded_dict;
}
