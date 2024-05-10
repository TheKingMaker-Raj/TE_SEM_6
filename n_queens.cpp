// #include<bits/stdc++.h>
// using namespace std;
// class NQueens
// {
//     public:
//     vector<string>board;
//     vector<vector<string>> ans;
//     int n = 0;

//     NQueens(int N)
//     {
//         n = N;
//         string s(n,'.');
//         for(int i = 0 ; i<n ; i++)
//         {
//             board.push_back(s);
//         }
//     }
    
//     bool isSafe(int row , int col)
//     {
//         int duprow = row;
//         int dupcol = col;

//         while(row>=0 && col>=0)
//         {
//             if(board[row][col] == 'Q')return false;
//             row--;
//             col--;
//         }

//         row = duprow;
//         col = dupcol;

//         while(col>=0)
//         {
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }

//         row = duprow;
//         col = dupcol;

//         while(row<n && col>=0)
//         {
//             if(board[row][col] == 'Q') return false;
//             row++;
//             col--;
//         }

//         return true;
//     }

//     void solve(int col)
//     {
//         if(col == n)
//         {
//             ans.push_back(board);
//             return;
//         }

//         for(int i = 0 ; i<n ; i++)
//         {
//             if(isSafe(i , col))
//             {
//                 board[i][col] = 'Q';
//                 solve(col+1);
//                 board[i][col] = '.';
//             }
//         }
//     }

//     void print()
//     {
//         int sz = ans.size();
//         for(int i = 0 ; i<sz ; i++)
//         {
//             for(int j = 0  ; j<n ; j++)
//             {
//                 for(int z = 0 ; z<n ; z++)
//                 {
//                     if(ans[i][j][z] == '.') cout<<" .";
//                     else cout<<" Q";
//                 }
//                 cout<<endl;
//             }
//         cout<<endl; 
//         }  

//     }
// };

// int main()
// {
//     cout<<"Enter N : ";
//     int k ; cin>>k;

//     NQueens n(k);
//     n.solve(0);

//     cout<<"All possible states  are :"<<endl;
//     cout<<"----------------------------------------Possible States ---------------------------------"<<endl;

//     n.print();
// }

#include<bits/stdc++.h>
using namespace std;

class NQueen{
    public:
    vector<string>board;
    vector<vector<string>> ans;
    vector<bool> col;
    vector<bool> nd;
    vector<bool> abd;
    int n;

    NQueen(int N)
    {
        n = N;
        col.resize(n);
        nd.resize(2*n-1,false);
        abd.resize(2*n-1,false);
        string s(n,'.');
        for(int i = 0 ; i<n ; i++)
        {
            board.push_back(s);
        }
    }

    bool isSafe(int row , int col)
    {
        int duprow = row;
        int dupcol= col;

        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow; col = dupcol;

        while(col>=0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow ; col= dupcol;

        while(row<n && col>=0)
        {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col )
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        else
        {
            for(int i = 0 ; i<n ; i++)
            {
                if(isSafe(i,col))
                {
                    board[i][col] = 'Q';
                    solve(col+1);
                    board[i][col] = '.';
                }
            }
        }
    }

    bool is_safe_2(vector<bool>col , vector<bool>nd , vector<bool> abd , int i , int j)
    {
        if(col[j] == false && nd[i+j] == false && abd[i-j+n-1] == false) return true;
        return false;
    }

    void solve_branchbound(int row)
    {
        if(row == n)
        {
            ans.push_back(board);
            return ;
        }

        for(int j = 0 ; j<n ; j++)
        {
            if(is_safe_2(col,nd,abd,row,j)){
                col[j] = true;
                nd[row+j] = true;
                abd[row-j+n-1] = true;
                board[row][j] = 'Q';
                solve_branchbound(row+1);
                board[row][j] = '.';
                col[j] = false;
                nd[row+j] = false;
                abd[row-j+n-1] = false;

            }
        }
    }

    void print()
    {
        for(int i = 0 ; i<ans.size() ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                for(int k = 0  ;k<n ; k++)
                {
                    cout<<ans[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<endl;
        }
    }
};


int main()
{
    NQueen nq(5);
    nq.solve_branchbound(0);
    nq.print();
}