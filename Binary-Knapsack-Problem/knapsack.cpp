#include<iostream>
using namespace std;





int knapOpt(int w[], int p[], int c, int n){

  int solMat[n+1][c+1];
  for (int i = 0; i < c+1; i++) {
    solMat[0][i] = 0;
  }

  for (int i = 1; i < n+1; i++) {
    for (int j = 0; j < c+1; j++) {
      if(i == 1 && j == 0){
        solMat[i][j] = 0;
        cout << solMat[i][j] << " ";
      }
      else{
        if(w[i-1] > j){
          solMat[i][j] = solMat[i-1][j];
        }
        else{
          solMat[i][j] = max(solMat[i-1][j], (p[i-1] + solMat[i-1][j-w[i-1]]));
        }
        cout << solMat[i][j] << " ";
      }
    }
    std::cout << '\n';
  }
  cout << solMat[n][c] << '\n';

  int newsolMat[n][c+1];
  for(int i = 0; i < n; i++){
    for (size_t j = 0; j < c+1; j++) {
      newsolMat[i][j] = solMat[i+1][j];
      cout << newsolMat[i][j] << " ";
    }
    std::cout << '\n';
  }
}





int main(){
  int w[] = {2,3,5,8,13,16}; //weights
  int p[] = {1,2,3,5,7,10}; //profits
  int c = 30; //capacity
  if(sizeof(w) != sizeof(p)){
    cout << "There must be some sort of mistake";
    return 0;
  }
  knapOpt(w,p,c,6);
}
