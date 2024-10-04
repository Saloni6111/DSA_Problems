class SplitLinkedListToParts {
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    } 
    public static ListNode[] splitListToParts(ListNode head, int k) {
        ListNode temp = head;
        ListNode pre = head;
        ListNode[] arr = new ListNode[k];
        int count = 0;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        temp = head;
        int i = 0;
        int mid = count / k;
        int extra = count % k;
        while (temp != null && i < k) {
            arr[i] = temp;
            int part = mid + (extra > 0 ? 1 : 0);
            for (int j = 0; j < part - 1; j++) {
                temp = temp.next;
            }
            pre = temp.next;
            temp.next = null;
            temp = pre;
            i++;
            extra--;
        }

        return arr;

    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        int k = 5;
        ListNode[]result = splitListToParts(head,k);
        for (int i = 0; i < result.length; i++) {
            System.out.print("Part " + (i + 1) + ": ");
            ListNode node = result[i];
            if(node == null){
                System.out.println("null");
            }else{
                while (node != null) {
                    System.out.print(node.val + " ");
                    node = node.next;
                }
            }
            System.out.println();
        }

    }
}