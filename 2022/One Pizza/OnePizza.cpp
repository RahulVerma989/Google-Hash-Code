#include <bits/stdc++.h>
using namespace std;

void appendUniqueList(vector<string>& list,string ingredient)
{
    bool duplicate = false;
    int length = list.end() - list.begin();

    for(int i = 0; !duplicate && i < length; i++)
    {
        if(list[i] == ingredient)
        {
            duplicate = true;
            break;
        }
    }

    if(!duplicate)
    {
        list.push_back(ingredient);
    }  
    // return list;
}

int main()
{
    int clients = 0, like = 0, dislike = 0;
    string clientLikes, clientDislikes;
    vector<string> likedIngredients;
    vector<string> dislikedIngredients;

    cin>>clients;

    while(clients)
    {
        cin>>like;

        for(int i = 0; i < like; i++)
        {
            cin>>clientLikes;
           appendUniqueList(likedIngredients,clientLikes);
        }

        cin>>dislike;

        for(int i = 0; i < dislike; i++)
        {
            cin>>clientDislikes;
            appendUniqueList(dislikedIngredients,clientDislikes);
        }
        clients--;
    } 

    //remove any disliked ingredients list from liked ingredient list
    vector<string> answer(likedIngredients.size());
    vector<string>::iterator answerEnd;
    answerEnd = set_difference(likedIngredients.begin(),likedIngredients.end(),dislikedIngredients.begin(),dislikedIngredients.end(),answer.begin());

    answer.resize(answerEnd - answer.begin());
    int length = answer.size();
    cout<<length<<" ";
    for(int i = 0; i < length; i++)
    {
        cout<<answer[i]<<" ";
    }
    return 0;
}