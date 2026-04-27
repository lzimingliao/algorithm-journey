public class Lc0145BinaryTreePostorderTraversal {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    class Solution {
        public static List<Integer> postorderTraversal(TreeNode root) {
            List<Integer> ans = new ArrayList<>();
            if (root == null)
                return ans;
            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode cur = stack.peek();
                if (cur.left != null && cur.left != root && cur.right != root)
                    stack.push(cur.left);
                else if (cur.right != null && cur.right != root)
                    stack.push(cur.right);
                else {
                    ans.add(cur.val);
                    root = stack.pop();
                }
            }
            return ans;
        }
    }
}