#include<bits/stdc++.h>
#include "observer.cpp"
using namespace std;

class subject{
    public:
        void registerObserber();
        void unRegisterObserber();
        void notifySubscriber();
};

class cricketData:subject{
    int runs;
    int wickets;
    float overs;
    list<observer> *observerList;

    public:
        cricketData(){
            observerList = new list<observer>();

        }
        void registerObserver(Observer *O){
            observerList->insert(O);
        }
        void unRegisterObserver(Observer *O){
            observerList->remove(O);
        }

        void notifySubscriber(){
            iterator<Observer> *temp= observerList->begin();
            while(temp!=NULL){
                temp->update(runs, wickets, overs);
                temp = temp->next;
            }
        }

    private:
        int getLatestRuns(){
            return 90;
        }
        int getLatestWickets(){
            return 2;
        }
        float getLatestOvers(){
            return  float(10.2);
        }
        void dataChanged(){
            runs = getLatestRuns();
            wickets = getLatestWickets();
            overs = getLatestOvers();
            notifySubscriber();
        }
};


int main(){
    AverageScoreDisplay *average_score_display = new AverageScoreDisplay();
    currentScore *current_score = new currentScore();

    cricketData *cricket_data = new cricketData();

    cricket_data->registerObserber(average_score_display);

    cricket_data->registerObserber(current_score);

    cricket_data->dataChanged();

    cricket_data->unRegisterObserber(averagescoredisplay);

    cricket_data->dataChanged();
    return 0;
}