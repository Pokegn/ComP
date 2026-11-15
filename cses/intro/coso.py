import re

# 1. Extract all 49-cell paths from your 12 MB C++ file
with open("grid_path_description.cpp", "r") as f:
  code = f.read()

raw_paths = re.findall(r"\{([0-9,\s]+)\}", code)
diff_to_char = {7: "D", -7: "U", -1: "L", 1: "R"}

move_strings = []
for p in raw_paths:
  nums = [int(x) for x in p.split(",") if x.strip()]
  if len(nums) == 49:
    moves = "".join(diff_to_char[nums[i + 1] - nums[i]] for i in range(48))
    move_strings.append(moves)

move_strings.sort()

# 2. Build a minimal DAWG (merges identical prefixes AND suffixes)
# Each node is a tuple of 4 child indices: (D, U, L, R), -1 if None
DIR_IDX = {"D": 0, "U": 1, "L": 2, "R": 3}

# Build Trie first using flat lists for speed
children = [[-1, -1, -1, -1]]
for s in move_strings:
  curr = 0
  for ch in s:
    d = DIR_IDX[ch]
    nxt = children[curr][d]
    if nxt == -1:
      nxt = len(children)
      children.append([-1, -1, -1, -1])
      children[curr][d] = nxt
    curr = nxt

# Minimize Trie bottom-up into a DAWG
memo = {}
dawg_nodes = []


def minimize(u):
  if u == -1:
    return -1
  sig = tuple(minimize(children[u][d]) for d in range(4))
  if sig in memo:
    return memo[sig]
  node_id = len(dawg_nodes)
  dawg_nodes.append(sig)
  memo[sig] = node_id
  return node_id


root = minimize(0)
# Reverse so root is index 0
N = len(dawg_nodes)
rev_nodes = []
for i in range(N - 1, -1, -1):
  rev_nodes.append(
      tuple(-1 if c == -1 else (N - 1 - c) for c in dawg_nodes[i])
  )

# 3. Serialize DAWG: each node has 4 child pointers (0..N, where 0 = null).
# Base-89 encode each pointer into 3 chars (89^3 = 704,969 > N) -> 12 chars/node
ALPH = "".join(
    chr(i) for i in range(35, 127) if chr(i) not in ('"', "\\", "?")
)
B = len(ALPH)  # 89


def enc_int(x):
  c0 = ALPH[x % B]
  x //= B
  c1 = ALPH[x % B]
  x //= B
  c2 = ALPH[x % B]
  return c0 + c1 + c2


blob = "".join(enc_int(c + 1) for node in rev_nodes for c in node)

cpp = f"""#include <bits/stdc++.h>
using namespace std;

const string ALPH = R"({ALPH})";
const char* DAWG = 
"""
for i in range(0, len(blob), 120):
  cpp += f'    "{blob[i:i+120]}"\n'

cpp += f""";

int nxt[{N}][4];
string s;
int ans = 0;

void count_paths(int u, int step) {{
    if (step == 48) {{
        ans++;
        return;
    }}
    char c = s[step];
    if ((c == '?' || c == 'D') && nxt[u][0] != -1) count_paths(nxt[u][0], step + 1);
    if ((c == '?' || c == 'U') && nxt[u][1] != -1) count_paths(nxt[u][1], step + 1);
    if ((c == '?' || c == 'L') && nxt[u][2] != -1) count_paths(nxt[u][2], step + 1);
    if ((c == '?' || c == 'R') && nxt[u][3] != -1) count_paths(nxt[u][3], step + 1);
}}

int main() {{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> s)) return 0;

    int inv[128] = {{}};
    for (int i = 0; i < (int)ALPH.size(); ++i) inv[(int)ALPH[i]] = i;

    const char* p = DAWG;
    for (int i = 0; i < {N}; ++i) {{
        for (int d = 0; d < 4; ++d) {{
            int val = inv[(int)p[0]] + inv[(int)p[1]] * {B} + inv[(int)p[2]] * {B * B};
            nxt[i][d] = val - 1;
            p += 3;
        }}
    }}

    count_paths(0, 0);
    cout << ans << '\\n';
}}
"""

with open("compressed.cpp", "w") as f:
  f.write(cpp)

print(
    f"Paths: {len(move_strings)} | DAWG nodes: {N} | Output size:"
    f" {len(cpp)/1024:.2f} KB"
)