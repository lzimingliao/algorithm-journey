public class Lc0002AddTwoNumbers {
    public class ListNode {
        public int val;
        public ListNode next;

        public ListNode(int val) {
            this.val = val;
        }

        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    class Solution {
        public ListNode addTwoNumbers(ListNode head1, ListNode head2) {
            ListNode ans = null, cur = null;
            int sum = 0, val = 0, carry = 0;
            while (head1 != null || head2 != null) {
                sum = carry;
                if (head1 != null) {
                    sum += head1.val;
                    head1 = head1.next;
                }
                if (head2 != null) {
                    sum += head2.val;
                    head2 = head2.next;
                }
                val = sum % 10;
                carry = sum / 10;
                if (ans == null) {
                    ans = new ListNode(val);
                    cur = ans;
                } else {
                    cur.next = new ListNode(val);
                    cur = cur.next;
                }
            }
            if (carry != 0) {
                cur.next = new ListNode(carry);
            }
            return ans;
        }
    }
}
