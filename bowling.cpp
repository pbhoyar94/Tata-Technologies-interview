#include <iostream>
#include <vector>
#include <limits>
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
    vector <int> roll;
    int first_try=0,second_try=0;
    for(int frame=0; frame<10; ++frame)
    {
      while(true)
      {
        cout<<"Frame:"<<frame + 1<<"first try:";
        cin>>first_try;
        if(cin.fail())
        {
            cout<<"invalid input, please enter the number"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(first_try >= 0 && first_try <= 10)
        {
            break;
        }
        else
        {
            cout<<"invalid input, Enter the value between 0 to 10"<<endl;
        }
      }
      if(first_try == 10)
      {
          roll.push_back(first_try);
          continue;
      }
      while(true)
      {
        cout<<"Frame:"<<frame + 1<<"second try:";
        cin>>second_try;
        if(cin.fail())
        {
            cout<<"invalid input, please enter the number"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(second_try >= 0 && second_try <= 10)
        {
            if(first_try + second_try <=10)
            {
                break;
            }
            else
            {
                cout<<"Invalid input. The sum of the two tries must not exceed value 10"<<endl;
            }    
        }
        else
        {
            cout<<"invalid input, Enter the value between 0 to 10"<<endl;
        }
      }
      roll.push_back(first_try);
      roll.push_back(second_try);
    }
    int total_score = bowlingScore(roll);
    cout<<"Total Bowling score: "<<total_score<<endl; 
    return 0;
}


