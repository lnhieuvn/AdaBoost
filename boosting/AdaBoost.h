/*
 * AdaBoost.h
 *
 *  Created on: 15/mar/2016
 *      Author: lorenzocioni
 */

#ifndef BOOSTING_ADABOOST_H_
#define BOOSTING_ADABOOST_H_

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>

#include "classifiers/StrongClassifier.h"
#include "classifiers/WeakClassifier.h"

using namespace std;
using namespace chrono;

class AdaBoost {

protected:
	int iterations;
	//Features and labels vector (must be the same size)
	vector<Data*> features;
	StrongClassifier* strongClassifier;
	WeakClassifier* trainWeakClassifier();
	virtual void normalizeWeights();
	virtual float updateAlpha(float error);
	virtual float updateBeta(float error);
	virtual void updateWeights(WeakClassifier* weakClassifier);

public:
	AdaBoost();
	AdaBoost(vector<Data*>& data, int iterations);
	int getIterations() const;
	void setIterations(int iterations);
	StrongClassifier* train();
	StrongClassifier* train(vector<WeakClassifier*>& classifiers);
	int predict(Data* x);
	void showFeatures();
	virtual ~AdaBoost();
};

#endif /* BOOSTING_ADABOOST_H_ */
