static string map_int[] = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
  using vchar = string;
  using vvchar = std::vector<string>;

  vvchar cartesian_two(vvchar &v_a, vchar &v_b) {
    vvchar result;
    for (int i = 0; i < v_a.size(); ++i) {
      for (int j = 0; j < v_b.size(); ++j) {
        vchar temp = v_a[i];
        temp.push_back(v_b[j]);
        result.push_back(temp);
      }
    }
    return result;
  }

  vvchar cartesian(vvchar &v_a) {
    auto size = v_a.size();
    auto size_0 = v_a[0].size();

    vvchar temp;
    for (int i = 0; i < size_0; ++i) temp.push_back({v_a[0][i]});

    for (int i = 1; i < size; ++i) {
      temp = cartesian_two(temp, v_a[i]);
    }
    return temp;
  }

 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return vector<string>();
    vvchar v;
    for (auto &el : digits) {
      auto idx = el - '0';
      v.push_back(map_int[idx]);
    }
    return cartesian(v);
  }
};