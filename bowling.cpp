#include <iostream>
#include <vector>
using namespace std;

int bowlingScore(const vector<int> &roll)
{
    int score=0;
    int frameIdx=0;
    for(int frame=0; frame<10; ++frame)
    {
        if(roll[frameIdx] == 10)
        {
            score += 10 + roll[frameIdx + 1] + roll[frameIdx + 2];
            frameIdx += 1;
        }
        else if((roll[frameIdx] + roll[frameIdx + 1]) == 10)
        {
            score += 10 + roll[frameIdx + 2]; 
            frameIdx += 2;
        }
        else
        {
            score += roll[frameIdx] + roll[frameIdx + 1]; 
            frameIdx += 2;
        }
    }
    return score;
}
int main()
{
    vector <int> roll = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};
    int total_score = bowlingScore(roll);
    cout<<"Total Bowling score: "<<total_score<<endl; 
    return 0;
}


