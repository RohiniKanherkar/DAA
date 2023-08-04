#include <iostream>
#include <cstring>

using namespace std;

#define d 256 // number of characters in the alphabet
#define q 101 // prime number used for hashing

void search(string txt, string pat) 
{
    int n = txt.length();
    int m = pat.length();
    int h = 1, p = 0, t = 0; // h: hash value for pattern, p: hash value for current window in txt, t: temporary variable for hash value
    int i, j;

    // precompute hash value of pattern and the initial hash value for the first window in txt
    for (i = 0; i < m-1; i++)
        h = (h*d) % q;
    for (i = 0; i < m; i++) 
	{
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }

    // slide the pattern over txt one by one
    for (i = 0; i <= n-m; i++) 
	{
        // check if the hash values for the current window in txt and the pattern match
        if (p == t) 
		{
            // check if the characters match
            for (j = 0; j < m; j++) 
			{
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // compute hash value for the next window of txt
        if (i < n-m) 
		{
            t = (d*(t - txt[i]*h) + txt[i+m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main() 
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    search(txt, pat);
    return 0;
}

