// Elements of an array A with index i < j and A[i] > A[j] is called inversions.
// This implementation modifies merge sort to find number of inversion

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& A, int p, int q, int r)
{
  // Begin by finding the final index of left and right array
  int nL = q - p + 1;
  int nR = r - q;

  // Then, copy elements from A into new array called L (left) and R (right)
  vector<int> L, R;
  for (int i = 0; i < nL; i++)
    L.push_back(A[p+i]);
  for (int j = 0; j < nR; j++)
    R.push_back(A[q+1+j]);
  
  // Sort them in order
  int i = 0, j = 0, k = p;
  int a0 = 0, count = 0;
  while (i < nL && j < nR)
  {
    if (L[i] < R[j])
    {
      A[k] = L[i++];
      a0++;
    }
    else
    {
      A[k] = R[j++];
      count += a0;
    }
    k++;
  }

  while (i < nL)
    A[k++] = L[i++];

  while (j < nR)
  {
    A[k++] = R[j++];
    count += a0;
  }

  return count;
}

int countInversion(vector<int>& A, int p, int r)
{
  if (p >= r)
    return 0;
  int q = (p + r) / 2;
  return countInversion(A, p, q) + countInversion(A, q+1, r) + merge(A, p, q, r);
}

int main()
{
  // Initialize the vector
  // vector<int> A = { 3, 41, 52, 26, 38, 57, 9, 49, 78, 62, 15, 87, 30, 72, 44, 16, 83, 50, 64, 21, 90, 36, 12, 47, 68, 53, 29, 93, 81, 5, 95, 60, 74, 18, 85, 7, 39, 25, 98, 14, 67, 11, 45, 92, 56, 63, 20, 34, 97, 31, 88, 23, 75, 40, 13, 82, 66, 48, 10, 28, 99, 19, 76, 6, 32, 55, 46, 22, 84, 8, 35, 89, 71, 24, 54, 17, 79, 2, 94, 61, 37, 80, 43, 33, 100, 4, 65, 27, 86, 1, 77, 42, 73, 91, 58, 70, 96, 59, 69, 51 };
  vector<int> A = { 2, 3, 8, 6, 1 };

  // Print vector
  cout << "Before sorted: ";
  for (auto it = A.begin(); it < A.end(); it++)
    cout << *it << " ";
  cout << "\n\n";

  cout << "The number of inversions of the array is: " << countInversion(A, 0, A.size()-1) << "\n\n";

  cout << "After sorted: ";
  for (auto it = A.begin(); it < A.end(); it++)
    cout << *it << " ";
  cout << "\n\n";
}

