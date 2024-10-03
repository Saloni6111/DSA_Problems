// A CSES PROBLEM SET QUESTION

//Time limit: 1.00 s
// Memory limit: 512 MB

// Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

//Input:
   // The only input line has a string of length n consisting of characters A–Z.Output
  //Print a palindrome consisting of the characters of the original string.You may print any valid solution.If there are no solutions,
 // print "NO SOLUTION".
   
// Constraints:  (1 <= n <= 10 ^6)

//Example:
       // input:AFFFBCACBZZTFUU
       // Output: ABCFFUZTZUFFCBA

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int counts = 0;
    int len = s.size();
    vector<char> vect(len);
    int count[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] % 2 != 0)
        {
            counts++;
        }
    }
    int k = 0;
    if (len % 2 != 0 && counts == 1)
    {

        for (int i = 0; i < 256; i++)
        {
            if (count[i] % 2 != 0)
            {
                vect[(len) / 2] = (char)i;
                count[i]--;
            }

            int hf = count[i] / 2;
            while (count[i] > hf)
            {
                vect[k++] = i;
                count[i]--;
            }
        }
        int kk = k + 1;
        for (int i = 0; i < k; i++)
        {
            vect[kk++] = vect[k - i - 1];
        }
        for (int i = 0; i < len; i++)
        {
            cout << vect[i];
        }
    }
    else if (len % 2 == 0 && counts == 0)
    {
        for (int i = 0; i < 256; i++)
        {
            if (count[i] != 0)
            {
                int vf = count[i] / 2;
                while (count[i] > vf)
                {
                    vect[k++] = i;
                    count[i]--;
                }
            }
        }
        int kkk = k;
        for (int j = 0; j < k; j++)
        {
            vect[kkk++] = vect[k - j - 1];
        }
        for (int i = 0; i < len; i++)
        {
            cout << vect[i];
        }
    }
    else
    {
        cout << "NO SOLUTION" << endl;
    }
    return 0;
}
