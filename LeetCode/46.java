import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> permutation = new ArrayList<Integer>();
        dfs(result, permutation, nums);
        return result;
    }

    private void dfs(List<List<Integer>> result, List<Integer> permutation, int[] nums) {
        if (permutation.size() == nums.length) {
            List<Integer> validPermutation = new ArrayList<Integer>(permutation);
            result.add(validPermutation);
        }
        for (int num : nums) {
            if (!permutation.contains(num)) {
                permutation.add(num);
                dfs(result, permutation, nums);
                permutation.remove(permutation.size() - 1);
            }
        }
    }
}
