#include <iostream>
#include <string>
using namespace std;

#define d 256

int rabinKarp(string text, string pattern, int q = 101)
{
	int n = text.length();
	int m = pattern.length();

	if (m > n)
	{
		return -1;
	}

	int h = 1;
	int p = 0;
	int t = 0;

	for (int i = 0; i < m - 1; i++)
	{
		h = (h * d) % q;
	}
	for (int i = 0; i < m; i++)
	{
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	}

	for (int i = 0; i <= n - m; i++)
	{
		if (p == t)
		{
			bool match = true;
			for (int j = 0; j < m; j++)
			{
				if (text[i + j] != pattern[j])
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				return i;
			}
		}

		if (i < n - m)
		{
			t = (d * (t - text[i] * h) + text[i + m]) % q;

			if (t < 0)
			{
				t += q;
			}
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

	int result = rabinKarp(text, pattern);

	if (result != -1)
	{
		cout << "Pattern found at index: " << result << endl;
	}
	else
	{
		cout << "Pattern not found." << endl;
	}
	return 0;
}
