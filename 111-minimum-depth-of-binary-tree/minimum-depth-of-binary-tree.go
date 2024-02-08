/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
    if root == nil{
        return 0
    }else{
        return findMinDepth(root,1)
    }

    
}

func findMinDepth(node* TreeNode, depth int) int{
    if node.Left == nil && node.Right == nil{
        return depth
    }else{
        if node.Left == nil{
            return findMinDepth(node.Right,depth+1)
        }else if node.Right == nil{
            return findMinDepth(node.Left,depth+1)
        }else{
            return int(math.Min(float64(findMinDepth(node.Left,depth+1)),float64(findMinDepth(node.Right,depth+1))))
        }
    }
}
