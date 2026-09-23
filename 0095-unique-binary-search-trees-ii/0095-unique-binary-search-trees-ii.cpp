class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = build(start, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }

        return result;
    }
};