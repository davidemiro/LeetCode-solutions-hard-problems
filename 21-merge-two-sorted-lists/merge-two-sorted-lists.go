/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    var result *ListNode;

    var iterator *ListNode
    x := true

    for list1 != nil || list2 != nil{
        if list2 == nil || (list1 !=nil && list1.Val < list2.Val){
            if x{
                x = false
                iterator = list1
                result = iterator
            }else{
                iterator.Next = list1
                iterator = iterator.Next
            }
            list1 = list1.Next
        }else{
            if x{
                x = false
                iterator = list2
                result = iterator
            }else{
                iterator.Next = list2
                iterator = iterator.Next
            }
            list2 = list2.Next

        }
        
    }
    return result
    
}