#include <iostream>
#include <limits>

using namespace std;

/**
 * @param merges the two subarrays of A from p-q and q+1 to r
 * A = [0, ..., p, ..., q, q+1, ..., r, ..., n]
 * A1 = [p, ..., q]
 * A2 = [q+1, ..., r]
 */
void merge(int A[], int p, int q, int r) {
  int n1 = q-p+1; // first array size
  int n2 = r-q; // second array size

  int A1[n1+1];
  for (int i = 0; i < n1; i++) {
    A1[i] = A[p+i];
  }
  A1[n1] = numeric_limits<int>::max();

  int A2[n2+1];
  for (int i = 0; i < n2; i++) {
    A2[i] = A[q+1+i];
  }
  A2[n2] = numeric_limits<int>::max();

  int i = 0;
  int j = 0;

  for (int a = p; a < r+1; a++) {
    if (A1[i] <= A2[j]) {
      A[a] = A1[i];
      i++;
    } else {
      A[a] = A2[j];
      j++;
    }
  }
}

void merge_sort(int A[], int p, int r) {
  if (p < r) {
    int q = (p+r)/2;
    merge_sort(A, p, q);
    merge_sort(A, q+1, r);
    merge(A, p, q, r);
  }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;

    cin >> N; cin.ignore();

    int horses[N];

    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horses[i] = Pi;
    }

    merge_sort(horses, 0, N-1);

    int min_diff = numeric_limits<int>::max();

    for (int i = 1; i < N; i++) {
        if (horses[i] - horses[i-1] < min_diff) {
            min_diff = horses[i] - horses[i-1];
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << min_diff << endl;
}
