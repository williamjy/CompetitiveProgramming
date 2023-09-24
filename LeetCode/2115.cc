class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        map<string, map<string, bool>> adjacentMatrixed;
        map<string, bool> visited;
        map<string, int> degrees;
        stack<string> s;
        for (int i = 0; i < recipes.size(); ++i) {
            auto recipe = recipes[i];
            for (int j = 0; j < ingredients[i].size(); ++j) {
                auto ingredient = ingredients[i][j];
                adjacentMatrixed[ingredient][recipe] = true;
                degrees[recipe]++;
                if (find(supplies.begin(), supplies.end(), ingredient) != supplies.end()) {
                    if (find(recipes.begin(), recipes.end(), ingredient) == recipes.end()) {
                        s.push(ingredient);
                    }
                } else {
                    visited[ingredient] = true;
                }
            }
        }
        visited.clear();
        vector<string> result;
        while (!s.empty()) {
            auto ingredient = s.top();
            s.pop();
            if (!visited[ingredient]) {
                visited[ingredient] = true;
                if (find(recipes.begin(), recipes.end(), ingredient) != recipes.end()) {
                    result.push_back(ingredient);
                }
                for (auto entry : adjacentMatrixed[ingredient]) {
                    auto nextIngredient = entry.first;
                    degrees[nextIngredient]--;
                    if (!visited[nextIngredient] && degrees[nextIngredient] == 0) {
                        s.push(nextIngredient);
                    }
                }
            }
        }
        return result;
    }
};