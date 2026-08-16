// class FileSystem {

//     // The TrieNode data structure.
//     class TrieNode {
        
//         String name;
//         int val = -1;
//         Map<String, TrieNode> map = new HashMap<>();
        
//         TrieNode (String name) {
//             this.name = name;
//         }
//     }
    
//     TrieNode root;
    
//     // Root node contains the empty string.
//     public FileSystem() {
//         this.root = new TrieNode("");
//     }
    
//     public boolean createPath(String path, int value) {
        
//         // Obtain all the components
//         String[] components = path.split("/");
        
//         // Start "curr" from the root node.
//         TrieNode cur = root;
        
//         // Iterate over all the components.
//         for (int i = 1; i < components.length; i++) {
            
//             String currentComponent = components[i];
            
//             // For each component, we check if it exists in the current node's dictionary.
//             if (cur.map.containsKey(currentComponent) == false) {
                
//                 // If it doesn't and it is the last node, add it to the Trie.
//                 if (i == components.length - 1) {
//                     cur.map.put(currentComponent, new TrieNode(currentComponent));
//                 } else {
//                     return false;
//                 }    
//             }
            
//             cur = cur.map.get(currentComponent);
//         }
        
//         // Value not equal to -1 means the path already exists in the trie. 
//         if (cur.val != -1) {
//             return false;
//         }
        
//         cur.val = value;
//         return true;
//     }
    
//     public int get(String path) {
        
//         // Obtain all the components
//         String[] components = path.split("/");
        
//         // Start "curr" from the root node.
//         TrieNode cur = root;
        
//         // Iterate over all the components.
//         for (int i = 1; i < components.length; i++) {
            
//             String currentComponent = components[i];
            
//             // For each component, we check if it exists in the current node's dictionary.
//             if (cur.map.containsKey(currentComponent) == false) {
//                 return -1;   
//             }
            
//             cur = cur.map.get(currentComponent);
//         }
        
//         return cur.val;
//     }
// }
class FileSystem {
    class TrieNode {
    public:
        string name;
        int val = -1;
        unordered_map<string, TrieNode*> mp;
        
        TrieNode(string name, int val) {
            this->name = name;
            this->val = val;
        }
    };

    vector<string> split(string const& input, char delimiter) {
        vector<string> tokens;
        istringstream stream(input);
        string token;

        while (getline(stream, token, delimiter)) {
            if(token.empty()) continue;
            tokens.push_back(token);
        }

        return tokens;
    }

    TrieNode* root;
public:
    FileSystem() {
        this->root = new TrieNode("", -1);
    }
    
    bool createPath(string path, int value) {
        vector<string> dirs = split(path, '/');
        TrieNode* cur = root;

        for(int i = 0; i < dirs.size(); i++) {
            string dir = dirs[i];
            if(cur->mp.count(dir)) {
                cur = cur->mp[dir];
            }

            else {
                if(i == dirs.size() - 1) {
                    cur->mp[dir] = new TrieNode(dir, value);
                    return true;
                }

                return false;
            }
        }

        if(cur->val != -1) return false;

        cur->val = value;
        return true;
    }
    
    int get(string path) {
        vector<string> dirs = split(path, '/');
        TrieNode* cur = root;

        for(int i = 0; i < dirs.size(); i++) {
            string dir = dirs[i];

            if(cur->mp.count(dir)) {
                cur = cur->mp[dir];
            }

            else return -1;
        }

        return cur->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
