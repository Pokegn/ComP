#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Table of costs
constexpr int gap = -1;
constexpr int match = 1;
constexpr int missmatch = -1;

// Function to align two sequences
// Returns the score of the alignment
// and modifies the strings s and t to be the aligned sequences
int alignment(string& s, string& t) {
  int n = s.size();
  int m = t.size();
  int dp[n + 1][m + 1];  // dp[i][j] = score of aligning s[0..i-1] and t[0..j-1]
  int choice[n + 1][m + 1];  // -1: remove, 0: (mis)match, 1: insert

  dp[0][0] = 0;

  for (int i = 1; i <= n; ++i) {  // Initialize first column
    dp[i][0] = dp[i - 1][0] + gap;
    choice[i][0] = -1;
  }

  for (int j = 1; j <= m; ++j) {  // Initialize first row
    dp[0][j] = dp[0][j - 1] + gap;
    choice[0][j] = 1;
  }

  // Fill the table
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // Consider three possible operations
      int match_mismatch =
          dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? match : missmatch);
      int remove = dp[i - 1][j] + gap;
      int insert = dp[i][j - 1] + gap;

      // Choose the best operation
      int best = max({match_mismatch, remove, insert});

      // Follow the order to break ties
      // Fill dp and save the choice made
      if (best == match_mismatch) {  // (mis)match
        dp[i][j] = match_mismatch;
        choice[i][j] = 0;
      } else if (best == remove) {  // remove
        dp[i][j] = remove;
        choice[i][j] = -1;
      } else {  // insert
        dp[i][j] = insert;
        choice[i][j] = 1;
      }
    }
  }

  // Reconstruct the aligned sequences
  string s_aligned = "";
  string t_aligned = "";
  int i = n;  // Start from the end
  int j = m;
  while (i > 0 || j > 0) {  // While we haven't reached the beginning

    // Follow the choice made, add the characters to the aligned sequences
    // and move to the next cell in the table considering the choice

    if (choice[i][j] == 0) {  // (mis)match
      s_aligned.push_back(s[i - 1]);
      t_aligned.push_back(t[j - 1]);
      --i;
      --j;
    } else if (choice[i][j] == -1) {  // remove
      s_aligned.push_back(s[i - 1]);
      t_aligned.push_back('-');
      --i;
    } else {  // insert
      s_aligned.push_back('-');
      t_aligned.push_back(t[j - 1]);
      --j;
    }
  }

  // Strings are built in reverse order
  reverse(s_aligned.begin(), s_aligned.end());
  reverse(t_aligned.begin(), t_aligned.end());

  // Modify the input strings and return the score
  s = s_aligned;
  t = t_aligned;
  return dp[n][m];
}

// Function to check if a string is a valid DNA sequence
bool check_sequence(string& s) {
  for (int i = 0; i < s.size(); ++i)
    if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T')
      return false;  // A, C, G, T are the valid characters

  return true;  // All characters are valid
}

int main() {
  string s, t;
  cin >> s;  // Get the first sequence

  bool flag = false;  // second sequence read
  while (cin >> t) {
    if (flag) {  // more than two sequences
      cout << "ERROR\n";
      return 0;
    }
    flag = true;  // second sequence has been read
  }

  if (t == "") {  // only one sequence
    cout << "ERROR\n";
    return 0;
  }

  // check both sequences are valid
  if (!check_sequence(s) || !check_sequence(t)) {
    cout << "ERROR\n";
    return 0;
  }

  // Align the sequences and print the result
  cout << alignment(s, t) << '\n';
  cout << s << '\n';
  cout << t << '\n';

  return 0;
}