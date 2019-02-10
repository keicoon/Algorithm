1. 주소 : https://leetcode.com/problems/add-two-numbers/solution/
2. 언어 : c#
3. 풀이  
```
2개의 링크드 리스트로 들어온 역순의 노드 값을 더하여 새로운 링크드 리스트를 반환하는 문제로  
올림되는 여부를 조심해서 매 링크드 리스트를 탐색하며 각 값을 더하고 새로운 노드를 만들어준다  
```
4. 코드
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode current = head;
        bool isHaving = false;
        
        while(l1 != null || l2 != null || isHaving) {
            int currentDigit = 0;
            
            if(l1 != null) {
                currentDigit += l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                currentDigit += l2.val;
                l2 = l2.next;
            }
            if(isHaving) currentDigit += 1;
            
            isHaving = false;
            
            if(currentDigit > 9) {
                isHaving = true;
                currentDigit %= 10;
            }
            
            ListNode currentDigitNode = new ListNode(currentDigit);
            current.next = currentDigitNode;
            current = currentDigitNode;
        }
        
        return head.next;
    }
}
```
