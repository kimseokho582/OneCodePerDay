
//틀린 풀이

// #include <iostream>
// #include <queue>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, ans = 0;
//         cin >> n;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int i = 0; i < n; i++)
//         {
//             int num;
//             cin >> num;
//             pq.push(num);
//         }

//         while (1)
//         {
//             int a = pq.top();
//             cout << "a: " << a << endl;
//             pq.pop();
//             int b = pq.top();
//             pq.pop();
//             cout << "b: " << b << endl;
//             ans += (a + b);
//             cout << "ans: " << ans << endl;
//             if (pq.empty())
//                 break;
//             pq.push(a + b);
//         }
//         cout << ans << "\n";
//     }
// }
