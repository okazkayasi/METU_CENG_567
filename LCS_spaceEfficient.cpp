#include<iostream>
using namespace std;

int lcsEff(char kisa[], char uzun[], int n1, int n2){

  int valMat[2][n1+1]; //space used is 2 * min(|M|, |N|)

  // first row is all zeros.
  for (int i = 0; i < n1+1; i++) {
    valMat[0][i] = 0;
    cout << valMat[0][i];
  }
  cout << endl;
  valMat[1][0] = 0;

  // Because we have 2 rows, we need to hold the modulo of the row number
  int indexHolder = 1; //this will hold the number of character of long array
  int upDown = 0; // this will be the row we will mutate
  int rev = 0; // this will be the row we compare

  for (int i = 0; i < n2; i++){
    cout << 0;
    upDown = indexHolder % 2;
    rev = (indexHolder+1) % 2;
    for (int j = 0; j < n1; j++){
      if(uzun[i] == kisa[j]){
        valMat[upDown][j+1] = valMat[rev][j] + 1;
      }
      else if (valMat[rev][j+1] > valMat[upDown][j]){
        valMat[upDown][j+1] = valMat[rev][j+1];
      }
      else{
        valMat[upDown][j+1] = valMat[upDown][j];
      }
      cout << valMat[upDown][j+1];
    }
    cout << endl;
    indexHolder++;
  }
  return(valMat[upDown][n1]);
}

int main(){

  char param1[] = {'b','d','c','a','b','a'};
  char param2[] = {'a','b','c','b','d','a','b'};
  int a;
  if (sizeof(param1)>sizeof(param2)) {
    a = lcsEff(param2,param1,sizeof(param2),sizeof(param1));
  }
  else{
    a = lcsEff(param1,param2,sizeof(param1),sizeof(param2));
  }
  cout << endl << "Longest Common Subsequence is " << a << " characters.";
  return 0;
}
