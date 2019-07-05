#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/cousins-in-binary-tree/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool findItem(TreeNode *r, int target, TreeNode *&parent, int &depth) {
        if (!r) return false;
        if (target == r->val) {
            return true;
        }
        int save_depth = depth;
        ++depth;
        parent = r;
        bool found = findItem(r->left, target, parent, depth);
        if (found) {
            return true;
        } else {
            depth = save_depth + 1;
            parent = r;
            return findItem(r->right, target, parent, depth);
        }
    }

    bool isCousins(TreeNode *root, int x, int y) {
        if (!root || x == y) return false;
        TreeNode *xp = nullptr;
        TreeNode *yp = nullptr;
        int dx = 0;
        int dy = 0;
        return findItem(root, x, xp, dx) &&
               dx >= 2 &&
               findItem(root, y, yp, dy) &&
               dx == dy &&
               xp != yp;
    }
};

void test1() {

    auto t1 = new TreeNode("1,2,3,null,4,null,5");
    cout << t1 << endl;
    cout << t1 << endl;
//    cout << "1 ? " << Solution().isCousins(t1, 4, 5) << endl;
    cout << "1 ? " << Solution().isCousins(t1, 5, 4) << endl;

//    auto t1 = new TreeNode("1,2,3,null,null,4,5");
//    cout << t1 << endl;
//    cout << "0 ? " << Solution().isCousins(t1, 4, 5) << endl;

//    auto t1 = new TreeNode("1,2,3,null,4");
//    cout << "0 ? " << Solution().isCousins(t1, 2, 3) << endl;

//    auto t2 = new TreeNode("1,2,3,4");
//    cout << "0 ? " << Solution().isCousins(t2, 4, 3) << endl;
}

void test2() {

}

void test3() {

}