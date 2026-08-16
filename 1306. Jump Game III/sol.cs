public class Solution {
    public bool CanReach(int[] arr, int start) {
        if (arr[start] == 0) return true;

        int n = arr.Length;
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        bool[] vis = new bool[n];
        vis[start] = true;

        while (q.Count > 0) {
            int i = q.Dequeue();

            if (i + arr[i] < n && !vis[i + arr[i]]) {
                if (arr[i + arr[i]] == 0) return true;
                q.Enqueue(i + arr[i]);
                vis[i + arr[i]] = true;
            } 

            if (i - arr[i] >= 0 && !vis[i - arr[i]]) {
                if (arr[i - arr[i]] == 0) return true;
                q.Enqueue(i - arr[i]);
                vis[i - arr[i]] = true;
            }
        }

        return false;
    }
}
