#include<bits/stdc++.h>
using namespace std;

class observer{
    public: 
        virtual void update(int runs, int wickets, int over) = 0;
};

class currentScore: observer{
    int Runs;
    int Wickets;
    int Over;

    public:
        void update(int runs, int wickets, int over){
            Runs = runs;
            Wickets = wickets;
            Over = over;
        }
        void show_score(){
            cout<<"Runs "<<Runs<<" Wickets "<< Wickets<< " Overs "<<Over<<endl;
        }
};

class AverageScoreDisplay: observer{
    int predictedScore;
    float runRate;

    public:
        void update(int runs, int wickets, int over){
            runRate = (1.0*runs/over);
            predictedScore = runRate*over;
        }
        void show_score(){
            cout<<"Predicted Socre "<<predictedScore<<" Run Rate is "<< runRate<<endl;
        }
};