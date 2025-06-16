#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

int arr[] = {1, 4, 7, 3, 7, 3, 8, 9, 4, 2, 5}; 
int n = sizeof(arr) / sizeof(arr[0]);
// bài 1
//  int main() {                                              // độ phức tạp thời gian của thuật toán là O(n)
//      int n = 1;
//      for (int i = 0; i < n; i++)
//      {
//          cout << "Hello, World!" << endl;
//      }
//      return 0;
//  }

// bài 2
// int main() {                                              // độ phức tạp thời gian của thuật toán là O(log n)
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     prinfDouble(n);
//     return 0;
// }
// void prinfDouble(int n) {
//     int i = 1;
//     while (i <= n) {
//         cout << i << endl;
//         i*= 2;
//     }
// }

// bài 3
// int* mallocArray(int n){
//     int* ar = (int*)malloc(n * sizeof(int));                 // độ phức tạp không gian của thuât toán là O(n)
//     for (int i = 0; i < n; i++)
//     {
//         ar[i] = i + 1;
//         cout << ar[i] << endl;
//     }
//     return ar;
// };

// bài 4

// cách 1                                                      // độ phức tạp cảu thuật toán là o(n)
// int total(int n) {
//     if (n == 0)
//     {
//         return 0;
//     };
//     cout << n << endl;
//     return n + total(n - 1);
// }

// cách 2
//  int total(int n) {                                            // độ phức tạp của thuật toán là O(1)
//     int sum = n * (n - 1) / 2;
//  }

// bài 5

//                                                                // độ phức tạp thời gian của thuật toán là o(n^2)
//                                                               // dộ phức tạp không gian của thuật toán là o(1)
// for (int i = 0; i < n - 1; i++)
// {
//     for (int j = 0; j < n - i - 1; j++)
//     {
//         if (arr[j] > arr[j + 1])
//         {
//             int temp = arr[j];
//             arr[j] = arr[j + 1];
//             arr[j + 1] = temp;
//         }
//     }
// }
// for (int i = 0; i < n; i++)
// {
//     cout << arr[i] << endl;
// }

// bài 6

//                                                                   // độ phức tạp thời gian của thuật toán là o(n^2)         
// int m = 5 ; // giả sử đến số lần suất hiện của 5                // dộ phức tạp không gian của thuật toán là o(1)
// int count = 0;
// for (int i = 0; i < n; i++)
// {
//     if (arr[i] == m)
//     {
//         count++;
//     }
// }

// bài 7 

// cách 1 

// for (int i = 0; i < n - 1; i++)                       // độ phức tạp thời gian của thuật toán là o(n^2)       
// {                                                      // dộ phức tạp không gian của thuật toán là o(1)
//     for (int j = i + 1; j < n; j++)
//     {
//         if (arr[i] == arr[j])
//         {
//             return true;
//         }
        
//     }
    
// }
// return false;

// cách 2
// int count[1001] = {0};                                //độ phức tạp thời gian của thuật toán là o(n)
//     for (int i = 0; i < n; i++) {                      // dộ phức tạp không gian của thuật toán là o(1)
//         if (count[arr[i]] > 0) {
//             return true; // Trùng lặp
//         }
//         count[arr[i]]++;
//     }
//     return false;
// }


//bài 8

// int maxCount = 0;                            // độ phức tạp của thuật toán o(n^2)
// int m;
// for (int i = 0; i < n; i++)
// {
//     int count = 1;
//     for (int j = 0; j < n; j++)
//     {
//         if (arr[i] == arr[j])
//         {
//             count++;
//         }
//     }
//     if (count > maxCount)
//     {
//         m = arr[i];
//     }
    
// }

//bài 9 

// int matrix[4][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};  // độ phức tạp về không gian o(1) , thời gian o(n^2)
// // in ra ma trận                                                                     
// for (int i = 0; i < 4; i++)
// {
//     for (int j = 0; j < 4; j++)
//     {
//         cout << matrix[i][j] << " ";
//     }
//     cout << endl;
// }
// //in đường chéo chính                         // độ phức tạp về thời gian o(n^2)
// for (int i = 0; i < 4; i++)
// {
//     for (int j = 0; j < 4; j++)
//     {
//        if (i == j)
//        {
//          cout << matrix[i][j] << " ";
//        }
       
//     }
//     cout << endl;
// }



// bài 10
// cách 1 
// bool laHoanVi(const string& s1, const string& s2) {      //Thời gian: O(n log n)
//     if (s1.length() != s2.length()) return false;                        //không gian o(n)

//     string sorted1 = s1;
//     string sorted2 = s2;

//     sort(sorted1.begin(), sorted1.end());
//     sort(sorted2.begin(), sorted2.end());

//     return sorted1 == sorted2;
// }


// cách 2
// bool laHoanVi(const string& s1, const string& s2) {      //Thời gian: O(n)
//     if (s1.length() != s2.length()) return false;        //khong gian o(1)

//     vector<int> count(256, 0); 

//     for (char c : s1) count[c]++;
//     for (char c : s2) count[c]--;

//     for (int val : count)
//         if (val != 0) return false;

//     return true;
// }


// int main() {
//     string str1 = "listen", str2 = "silent";

//     if (laHoanVi(str1, str2))
//         cout << "Hoán vị " << endl;
//     else
//         cout << "Không phải hoán vị " << endl;

//     return 0;
// }