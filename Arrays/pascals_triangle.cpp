// prints the pascal's triangle till the end of the nth row
vector<vector<long long int>> printPascal(int n)
{

  vector<vector<long long>> r(n);

  for (int i = 0; i < n; i++)
  {
    r[i].resize(i + 1);    // make sure no of rows = no. of columns
    r[i][0] = r[i][i] = 1; // initializes the first and the last element of the ith row as 1

    for (int j = 1; j < i; j++)
      r[i][j] = r[i - 1][j - 1] + r[i - 1][j]; // the concept of pascal's triangle is used here
  }
  return r;
}

//Time Complexity --> 

// print the nth row of the pascal's triangle
vector<int>(rowIndex + 1, 0);

v[0] = 1;
for (int i = 0; i < rowIndex; i++)
{
  for (int j = 1; j >= i; j--)
    v[j] += v[j - 1];
}
return v;