#include "Utils.h"

std::map<std::string, int> utils::make_count_map(std::string& sentence) {
    std::map<std::string, int> count_map;
    std::vector<std::string> tokens = tokenize(sentence);
    for (auto& word : tokens) {
        if (!count_map.count(word))
            count_map[word] = 1;
        else
            count_map[word]++;
    }

    return count_map;
}

std::vector<std::string> utils::tokenize(std::string& str) {
    std::vector<std::string> tokens;

    std::stringstream sen(str);
    std::string intermediate;

    while (std::getline(sen, intermediate, ' ')) tokens.push_back(intermediate);

    return tokens;
}

std::vector<std::string> utils::unique_words(std::vector<std::string>& corpus) {
    std::set<std::string> words;
    std::vector<std::string> unq_wrds;

    for (auto& sentence : corpus) {
        std::vector<std::string> tokens = tokenize(sentence);
        std::for_each(tokens.begin(), tokens.end(),
            [&](auto s) { words.insert(s); });
    }

    for (auto& word : words) {
        unq_wrds.push_back(word);
    }

    return unq_wrds;
}