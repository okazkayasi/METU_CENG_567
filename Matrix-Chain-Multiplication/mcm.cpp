#include<iostream>
using namespace std;

int mcmFinder(int columns[], int rows[], int n){
  int valMat[n][n];
  for (int i = 0; i < n; i++){
    valMat[i][i] = 0;
  }

  int i = 0;
  int col = 1;
  int row = 0;

  while (i < n){
    row = 0;
    col = row + i + 1;
    while (col < n) {
      int minHold = 9999999;
      for (int k = row; k < col; k++) {
        int hold = valMat[row][k]+valMat[k+1][col]+rows[row]*columns[k]*columns[col];
        cout << "Hold: " << hold << endl;
        minHold = min(minHold, hold);
      }
      valMat[row][col] = minHold;
      cout << valMat[row][col] << endl;
      cout << "col " << col << endl << "row " << row << endl << "n " << n << endl << endl;
      col++;
      row++;
    }
    i++;
  }
}


int main(){
  int columns[] = {35,15,5,10,20,25};
  int rows[] = {30,35,15,5,10,20};
  if(sizeof(columns) != sizeof(rows)){
    cout << "There must be some sort of mistake";
    return 0;
  }
  mcmFinder(columns,rows, 6);
}
