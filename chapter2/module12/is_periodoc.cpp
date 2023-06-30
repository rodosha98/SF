#include<iostream>
#include<string>

using namespace std;

bool IsKPeriodic(const string& str, int k);
int main(void)
{
    const string str = "abcabcabcabcabcabcabcabcabcabc";
    cout << IsKPeriodic(str, 3) << endl;
    cout << IsKPeriodic(str, 6) << endl;
    cout << IsKPeriodic(str, 2) << endl;

}

bool IsKPeriodic(const string& str, int k)
{
    if (str.size() % k != 0)
    {
        return false;
    }
    else
    {
        int j = k - 1;
        int i = j + k;

        while (j > 0)
        {
            while ( i < str.size())
            {
                if (str[i] != str[j])
                {
                    return false;
                }
                i += k;
            }
            j--;
        }
    }

    return true;
}