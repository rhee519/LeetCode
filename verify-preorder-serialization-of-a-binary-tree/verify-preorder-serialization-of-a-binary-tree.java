class Solution {
    public int check(ArrayList<String> nodes, int start) {
        int len = nodes.size();
        if(len <= 2) return -1;
        for(int i = start; i < len - 2; i++) {
            if(!nodes.get(i).equals("#") && nodes.get(i+1).equals("#") && nodes.get(i+2).equals("#")) {
                start = i+1;
                return i;
            }
        }
        return -1;
    }
    
    public boolean isValidSerialization(String preorder) {
        ArrayList<String> nodes = new ArrayList<>(Arrays.asList(preorder.split(",")));
        System.out.println(nodes);
        int i = 0;
        int next = 0;
        while(true) {
            i = check(nodes, next);
            if(i == -1) i = check(nodes, 0);
            if(i == -1) break;
            nodes.remove(i+2);
            nodes.remove(i+1);
            nodes.set(i, "#");
            next = i+1;
            if(next >= nodes.size() - 2) next = 0;
            System.out.println(nodes);
            System.out.println("next: " + next);
        }
        
        return nodes.size() == 1 && nodes.get(0).equals("#");
    }
}