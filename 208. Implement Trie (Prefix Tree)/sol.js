var Trie = function() {
    this.root = new Node();
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let cur = this.root;

    for(let x of word) {
        if(!cur.children[x]) {
             cur.children[x] = new Node();
        }
        cur = cur.children[x];
    }

    cur.word = true;
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    let cur = this.root;

    for(let x of word) {
        if(!cur.children[x]) {
            return false;
        }
        cur = cur.children[x];
    }

    return cur.word;
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    let cur = this.root;

    for(let x of prefix) {
        console.log(x);
        if(!cur.children[x]) {
            return false;
        }
        cur = cur.children[x];
    }

    return true;
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
