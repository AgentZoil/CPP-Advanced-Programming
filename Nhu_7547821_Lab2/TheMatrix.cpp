/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 2
Task 4
*/
#include <iostream>

using namespace std;

void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols)
{
    //Check the input valid
    if (M1_cols != M2_rows)
    {
        cout << "Invalid Matrix Dimensions" << endl;
        return;
    }

    //Store the results in another matrix M3
    float M3[10][10] = {0};

    for (int i = 0; i < M1_rows; ++i)
    {
        for (int j = 0; j < M2_cols; ++j)
        {
            for (int k = 0; k < M1_cols; ++k)
            {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }

    for (int i = 0; i < M1_rows; ++i)
    {
        for (int j = 0; j < M2_cols; ++j)
        {
            // M3 with elements of 2 decimal places, separated by blank spaces, and each row is printed on a new line
            cout << float(int(M3[i][j] * 100)) / 100;
            if (j < M2_cols - 1)
            {
                cout << " ";
            }
        }
        cout << " " << endl;
    }
}

int main()
{
    float M1[10][10] = {{0.1067, 0.7749}, {0.9619, 0.8173}, {0.0046, 0.8687}};
    float M2[10][10] = {{0.0844, 0.2599}, {0.3998, 0.8001}};
    multiplyMatrices(M1, M2, 3, 2, 2, 2);

}
