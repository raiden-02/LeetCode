bool helper(const int n, int* leftChild, int* rightChild, int ind, bool *invis) {
    if(ind >= n) return true;

    bool ans = true;

    if(leftChild[ind] != -1) {

        if(!invis[leftChild[ind]]) {
            invis[leftChild[ind]] = true;
            ans &= helper(n, leftChild, rightChild, leftChild[ind], invis);
        }

        else return false;
    }

    if(rightChild[ind] != -1) {

        if(!invis[rightChild[ind]]) {
            invis[rightChild[ind]] = true;
            ans &= helper(n, leftChild, rightChild, rightChild[ind], invis);
        }

        else return false;
    }
    return ans;
}

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize) {
    if(n == 1) return true;

    int indeg[n];
    memset(indeg, 0, sizeof(indeg));
    
    for(int i = 0; i < n; i++) {
        if(leftChild[i] != -1) indeg[leftChild[i]]++;
        if(rightChild[i] != -1) indeg[rightChild[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(leftChild[i] == -1 && rightChild[i] == -1 && indeg[i] == 0) 
            indeg[i] = -1;
    }
    
    int startNodeCnt = 0;

    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) startNodeCnt++;
        if(indeg[i] > 1) return false;
        if(startNodeCnt > 1) return false;
    }
    
    bool invis[n];
    memset(invis, false, sizeof(invis));
    
    bool ans = true;

    for(int i = 0; i < n; i++) {
        if(indeg[i] != 0) continue;
        invis[i] = true;
        ans &= helper(n, leftChild, rightChild, i, invis);
    }

    for(int i = 0; i < n; i++) {
        if(!invis[i]) return false;
    }

    return ans;
}
