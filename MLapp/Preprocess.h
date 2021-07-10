#pragma once
#ifndef _PREPROCESS_H__
#define _PREPROCESS_H__

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

class Preprocess {
private:
	/**
	 * @brief vecotr of string labels or categorical features
	 *
	 */
	std::vector<std::string> labels;

	/**
	 * @brief impute missing values in a feature by substituting mean.
	 *
	 * @tparam T
	 * @param feature_column
	 * @return std::vector<T>
	 */
	template <typename T>
	std::vector<T> impute_column_by_mean(std::vector<T> feature_column);

public:
	/**
	 * @brief Construct a new Preprocess object
	 *
	 * @param labels
	 */
	Preprocess(std::vector<std::string>& labels) : labels(labels) {}

	/**
	 * @brief one hot encode labels or features
	 *
	 * @return std::map<std::string, std::vector<int>>
	 */
	std::map<std::string, std::vector<int>> one_hot_encode();
};

#endif