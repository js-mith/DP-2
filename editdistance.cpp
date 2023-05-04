#include<iostream>
using namespace std;

int editdistance(string s , string t){
    if(s.size() == 0 || t.size() == 0 ){
        return max(s.size() , t.size());
    }

    if(s[0] == t[0]){
        return editdistance(s.substr(1) , t.substr(1));
    }

    else{
        // insert 
        int x = editdistance(s.substr(1),t)+1;

        //delete

        int y = editdistance(s, t.substr(1))+1;

        //replace

        int z = editdistance(s.substr(1) , t.substr(1)) +1 ;

        return min(x , min(y,z));
    }
}

int editdistance_mem(string s , string t , int **output){

     int m = s.size();
     int n = t.size();

     if(s.size() == 0 || t.size() == 0 ){
        return max(s.size() , t.size());
    }

    if(output[m][n] != -1){
        return output[m][n];
    }
     
     int ans;
    if(s[0] == t[0]){
        ans =  editdistance_mem(s.substr(1) , t.substr(1) , output);
    }

    else{
        // insert 
        int x = editdistance_mem(s.substr(1),t , output)+1;

        //delete

        int y = editdistance_mem(s, t.substr(1) , output)+1;

        //replace

        int z = editdistance_mem(s.substr(1) , t.substr(1) , output) +1 ;

        ans =  min(x , min(y,z));

        output[m][n] = ans;
    }

    return ans;


}

int editdistance_mem(string s, string t){
    int m = s.size();
    int n = t.size();

    int **ans = new int*[m+1];

    for(int i =0 ; i<=m ; i++){
        ans[i] = new int[n+1];

        for(int j =0 ; j<=n; j++){
            ans[i][j] = -1;
        }
    }

    return editdistance_mem(s,t,ans);
    
}

int editdistance_dp(string s , string t){
     int m = s.size();
    int n = t.size();

    int **output = new int*[m+1];
    for(int i =0 ; i <= m ;i ++){
        output[i] = new int[n+1];
    }

    // fill ist row

    for(int j = 0 ; j<=n ; j++){
        output[0][j] = 0;
    }

    //fill ist colm

    for(int i = 1 ; i<=m ; i++){
        output[i][0] =0;
    }

    for(int i = 1; i<= m ; i++){
        for(int j = 1 ; j<=n ; j++){
            //check if ist char matter

            if(s[m-i] == t[n-j]){
                output[i][j] = output[i-1][j-1];
            }

            else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];

                output[i][j] = min(a,min(b,c)) + 1;
            }
        }
    }

    return output[m][n];
}

int main() {
     string s ,t;

     cin>>s>>t;

     cout << editdistance(s,t) << endl;

     cout << editdistance_dp(s,t) << endl;
     return 0;
}