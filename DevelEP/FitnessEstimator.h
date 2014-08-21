// run fitness estimator evolution.
#pragma once
#ifndef FITNESSESTIMATOR_H
#define FITNESSESTIMATOR_H

class FitnessEstimator{
public:
	vector <int> FEpts; // points of fitness estimation (subset from data vals)
	//vector <float> TrainerFit; // fitness on trainer population
	float fitness; // self fitness across trainers

	FitnessEstimator(){fitness=0;}

	FitnessEstimator(int length,vector<Randclass>& r,data& d,bool train)
	{
		int lastpt;
		if (train) lastpt = d.vals.size()/2-1;
		else lastpt = d.vals.size()-1;
		for (int i=0;i<length;i++){
			FEpts.push_back(r[omp_get_thread_num()].rnd_int(0,lastpt));
		}
		fitness=0;
	}
	~FitnessEstimator(){}
	
};
void InitPopFE(vector <FitnessEstimator>& FE,vector<ind> &pop,vector<ind>& trainers,params p,vector<Randclass>& r,data& d,state& s);
void EvolveFE(vector<ind> &pop, vector <FitnessEstimator>& FE,vector <ind>& trainers,params p,data& d,state& s,vector<Randclass>& r);
void setFEvals(vector<vector<float>>& FEvals, vector<float>& FEtarget,FitnessEstimator& FE, data& d);
void PickTrainers(vector<ind> pop, vector <FitnessEstimator>& FE,vector <ind>& trainers,params p,data& d,state& s);
#endif