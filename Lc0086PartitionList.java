public class Lc0086PartitionList {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    class Solution {
        public ListNode partition(ListNode head, int x) {
            ListNode leftHead = null, leftTail = null;
            ListNode rightHead = null, rightTail = null;
            ListNode cur = head;
            while (cur != null) {
                if (cur.val < x) {
                    if (leftHead == null) {
                        leftHead = cur;
                        leftTail = cur;
                    } else {
                        leftTail.next = cur;
                        leftTail = leftTail.next;
                    }
                } else {
                    if (rightHead == null) {
                        rightHead = cur;
                        rightTail = cur;
                    } else {
                        rightTail.next = cur;
                        rightTail = rightTail.next;
                    }
                }
                cur = cur.next;
            }
            if (rightTail != null)
                rightTail.next = null;
            if (leftTail != null)
                leftTail.next = rightHead;
            return leftHead != null ? leftHead : rightHead;
        }
    }
}
