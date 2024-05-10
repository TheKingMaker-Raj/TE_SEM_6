// #include<bits/stdc++.h>
// using namespace std;


// int hue(vector<vector<int>> &state , vector<vector<int>> & grid , int level)
// {
//     int cnt = 0;
//     for(int i = 0 ; i<3 ; i++)
//     {
//         for(int j = 0 ; j<3 ; j++)
//         {
//             if(state[i][j] != -1)
//             {
//                 if(state[i][j] != grid[i][j])
//                 {
//                     cnt++;
//                 }
//             }
//         }
//     }

//     return level+cnt;
// }


// int main()
// {
//     vector<vector<int>> start(3,vector<int>(3));
//     vector<vector<int>> final(3,vector<int>(3));

//     cout<<"Enter starting state : "<<endl;
//     for(int i = 0 ; i<3 ; i++)
//     {
//         for(int j = 0 ; j<3 ; j++)
//         {
//             int k ; cin>>k;
//             start[i][j] = k;
//         }
//     }


//     cout<<"Enter starting state : "<<endl;
//     for(int i = 0 ; i< 3 ; i++)
//     {
//         for(int j = 0 ; j<3 ; j++)
//         {
//             int k ; cin>>k;
//             final[i][j] = k;
//         }
//     }

//     priority_queue<pair<int,pair<int,vector<vector<int>>>> , vector<pair<int,pair<int,vector<vector<int>>>>> , greater<pair<int,pair<int,vector<vector<int>>>>>> pq;

//     //sort on the basis of fn
//     //pq is=> {fn,{level,state}}
//     pq.push({0,{0,start}});
//     bool bk = false;
//     while(!pq.empty())
//     {
//         int fn = pq.top().first;
//         int lvl = pq.top().second.first;
//         vector<vector<int>> temp = pq.top().second.second;
//         pq.pop();

//         cout<<"Selected State  : is"<<endl;

//         for(int i = 0 ; i<3 ; i++)
//         {
//             for(int j = 0 ; j<3 ; j++)
//             {
//                 cout<<temp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         if(temp == final) break;

//         int x = 0;
//         int y = 0;
//         for(int i = 0 ; i<3 ; i++)
//         {
//             for(int j = 0 ; j<3 ; j++)
//             {
//                 if(temp[i][j] == -1)
//                 {
//                     x = i;
//                     y = j;
//                     break;
//                 }
//             }
//         }

//         int nrow [] = {0,-1,0,1};
//         int ncol[] = {-1,0,1,0};

//         for(int i = 0 ; i<4 ; i++)
//         {
//             int new_row = x + nrow[i];
//             int new_col = y + ncol[i];
//             if(new_col>=0 && new_row>= 0 && new_col<3 && new_row < 3)
//             {
//                 swap(temp[x][y] , temp[new_row][new_col]);
//                 cout<<"New Possible State is : "<<endl;
//                 for(int i = 0 ; i<3 ; i++)
//                 {
//                     for(int j = 0 ; j<3 ; j++)
//                     {
//                         cout<<temp[i][j]<<" ";
//                     }
//                     cout<<endl;
//                 }

//                 cout<<"h(n) : "<<hue(temp,final,lvl+1)<<endl;
//                 cout<<"g(n) : "<<lvl+1;
//                 cout<<"f(n) : "<<hue(temp,final,lvl+1) + lvl + 1<<endl;
//                 cout<<endl;
//                 if(hue(temp,final,lvl+1) == 0){
//                     bk = true;
//                     break;
//                 }
//                 if(hue(temp,final,lvl+1) != 0)pq.push({lvl+1+hue(temp,final,lvl+1) , {lvl+1,temp}});
//                 swap(temp[x][y] , temp[new_row][new_col]);
//             }
//         }

//         if(bk)break;

//     }

// }



    //initial   final
    // 1 2 3    1 2 3
    // -1 4 6   4 5 6
    // 7 5 8    7 8 -1


#include<bits/stdc++.h>
using namespace std;

int hue(vector<vector<int>> state , vector<vector<int>> grid)
{
    int cnt = 0;
    for(int i = 0 ; i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            if(state[i][j] != -1)
            {
                if(state[i][j] != grid[i][j]) cnt++;
            }
        }
    }
    return cnt;
}

pair<int,int> helper(vector<vector<int>> state)
{
    for(int i = 0 ;i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            if(state[i][j] == -1)
            {
                return {i,j};
            }
        }
    }
}

int main()
{
    vector<vector<int>> ini(3,vector<int>(3));
    vector<vector<int>> grid(3,vector<int>(3));

    cout<<"Enter the starting state:"<<endl;
    for(int i = 0 ; i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            int k ; cin>>k;
            ini[i][j] = k;
        }
    }

    cout<<"Enter the final state"<<endl;
    for(int i = 0 ; i<3 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            int k ; cin>>k;
            grid[i][j] = k;
        }
    }

    priority_queue<pair<int,pair<int,vector<vector<int>>>> , vector<pair<int,pair<int,vector<vector<int>>>>> , greater<pair<int,pair<int,vector<vector<int>>>>>> pq;

    pq.push({0,{0,ini}});
    while(!pq.empty())
    {
        int fn = pq.top().first;
        int level = pq.top().second.first;
        vector<vector<int>>state = pq.top().second.second;
        cout<<"selected state is : "<<endl;
        for(int i = 0 ; i<3 ; i++)
        {
            for(int j = 0  ; j<3 ; j++)
            {
                cout<<state[i][j]<<" ";
            }
            cout<<endl;
        }
        
        if(state == grid) break;
        pq.pop();

        pair<int,int> p = helper(state);
        int row = p.first;
        int col = p.second;

        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};

        for(int i = 0 ; i<4 ; i++)
        {
            int nrow = row +drow[i];
            int ncol = col +dcol[i];

            if(nrow>=0 && ncol>=0 && nrow<3 && ncol< 3)
            {
                cout<<"One of the possible state is :"<<endl;
                swap(state[row][col] , state[nrow][ncol]);
                for(int i = 0 ; i<3 ; i++)
                {
                    for(int j = 0 ; j<3 ; j++)
                    {
                        cout<<state[i][j]<<" ";
                    }
                    cout<<endl;
                }

                cout<<"h(n) : "<<hue(state,grid);
                cout<<"g(n) : "<<level+1;
                cout<<"f(n) : "<<hue(state,grid)+level+1;
                cout<<endl;
                pq.push({hue(state,grid)+level+1, {level+1 , state}});
                swap(state[row][col] , state[nrow][ncol]);
            }
        } 
    }
}