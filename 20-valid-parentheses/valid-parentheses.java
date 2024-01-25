class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        char[] chars = s.toCharArray();
        char x;
        for(char c : chars){
            if(c =='(' || c =='[' || c == '{'){
                stack.push(c);
            }
            else{
                if(stack.size() == 0) return false;
                x = stack.pop().charValue();
                if(x == '(' && (c==']' || c =='}')){
                    return false;
                }
                if(x == '[' && (c=='}' || c ==')')){
                    return false;
                }
                if(x == '{' && (c==']' || c ==')')){
                    return false;
                }
            }
        }
        return stack.size() == 0;
        
    }
}