/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil{
        return head
    }
    prev_iterator := head
    iterator := head.Next
    for iterator != nil{
        if iterator.Val == prev_iterator.Val{
            prev_iterator.Next = iterator.Next
        }else{
            prev_iterator = iterator
        }
        iterator = iterator.Next

        

    }

    return head
    
}