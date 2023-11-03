import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> tmp = new ArrayList<Integer>();
        int index = 0;
        dfs(candidates, target, result, tmp, index);
        return result;
    }
    
    void dfs(int[] candidates, int target, List<List<Integer>> result, List<Integer> tmp, Integer index) {
        if (target == 0) {
            result.add(new ArrayList<>(tmp));
        } else if (target < 0) {
            return;
        } else {
            Integer prevCandidate = 0;
            for (int currIndex = index; currIndex < candidates.length; ++currIndex) {
                Integer candidate = candidates[currIndex];
                if (prevCandidate != candidate) {
                    prevCandidate = candidate;
                    target -= candidate;
                    tmp.add(candidate);
                    dfs(candidates, target, result, tmp, currIndex + 1);
                    tmp.remove(Integer.valueOf(candidate));
                    target += candidate;
                }
            }
        }
    }
}