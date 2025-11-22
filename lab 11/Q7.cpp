#include <iostream>
#include <string>
using namespace std;

int bruteForceSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    if (m == 0)
    {
        return 0;
    }
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    int index = bruteForceSearch(text, pattern);

    if (index != -1)
    {

        cout << "Pattern found at index: " << index << endl;
    }
    else
    {

        cout << "Pattern not found." << endl;
    }

    return 0;
}

