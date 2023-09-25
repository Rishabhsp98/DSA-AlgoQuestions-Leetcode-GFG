import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    static List<Integer> maxCombinations(int N, int k, int A[], int B[]) {
        // code here
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Arrays.sort(A);
        Arrays.sort(B);
        
        for(int i=N-1;i>N-k-1;i--)
        {
            for(int j=N-1;j>N-k-1;j--)
            {
                int sum = A[i] + B[j];
                // pq.add(sum);
                if(pq.size() < k)
                {
                    pq.add(sum);
                }
                else{
                    if(pq.peek() < sum)
                    {
                        pq.poll();
                        pq.add(sum);
                    }
                    else
                        break;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        while(pq.size() != 0)
        {
            int ele = pq.poll();
            // pq.poll();
            ans.add(ele);
        }
        Collections.sort(ans,Collections.reverseOrder());
        return ans;
    }
}