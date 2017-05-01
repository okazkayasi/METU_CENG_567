#include<iostream>
using namespace std;

int lcsFinder(char param1[], char param2[], int m1, int m2){


  int UP = 1;
  int LEFT = 2;
  int LEFTUP = 3;

  int valMat[m1+1][m2+1];
  int pathFind[m1][m2];
  int i,j;
  for (i = 0; i <= m1; i++) {
    valMat[i][0] = 0;
  }
  for (i = 0; i <= m2; i++){
    valMat[0][i] = 0;
  }

  for (i = 1; i <= m1; i++){
    for (j = 1; j <= m2; j++) {
      if (param1[i-1] == param2[j-1]) {
        valMat[i][j] = valMat[i-1][j-1] + 1 ;
        pathFind[i-1][j-1] = LEFTUP;
      }
      else if(valMat[i][j-1] > valMat[i-1][j]){
        valMat[i][j] = valMat[i][j-1];
        pathFind[i-1][j-1] = LEFT;
      }
      else{
        valMat[i][j] = valMat[i-1][j];
        pathFind[i-1][j-1] = UP;
      }
    }
  }
  for (i = 0; i < m1+1; i++) {
    for (j = 0; j < m2+1; j++) {
      cout << valMat[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (i = 0; i < m1; i++) {
    cout << 0 << ' ';
    for (j = 0; j < m2; j++) {
      cout << pathFind[i][j] << " ";
    }
    cout << endl;
  }

  char seq[valMat[m1][m2]];
  int h1 = m1-1;
  int h2 = m2-1;
  int seqHolder =  valMat[m1][m2]-1;
  for (i = m1; i > 0; i--) {
    if (pathFind[h1][h2] ==   LEFTUP){
      seq[seqHolder] = param1[h1];
      cout << endl;
      cout << h1 << h2;
      cout << param1[h1];
      cout <<endl << "seqHolder:" << seqHolder;
      seqHolder--;
      h1--;
      h2--;
    }
    if(pathFind[h1][h2] == LEFT){
      h2--;
    }
    if(pathFind[h1][h2] == UP){
      h1--;
    }
  }

  cout <<endl << seq[0] << seq[1] << seq[2] << seq[3];

  return(valMat[m1][m2]);
}



int main(){
  char param1[7] = {'A','B','C','B','D','A','B'};
  char param2[6] = {'B','D','C','A','B','A'};
  //cout << (param1[2] == param2[1]) << endl;
  cout << endl << "length of LCS: " << lcsFinder(param1, param2, 7, 6);
  return 0;
}
