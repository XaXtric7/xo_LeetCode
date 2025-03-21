class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        graph = defaultdict(list)
        degree = defaultdict(int)

        for i, recipe in enumerate(recipes):
            for ingredient in ingredients[i]:
                graph[ingredient].append(recipe)
                degree[recipe] += 1
        
        queue = deque(supplies)
        res = []

        while queue :
            supply = queue.popleft()
            for recipe in graph[supply]:
                degree[recipe] -= 1
                if degree[recipe] == 0:
                    res.append(recipe)
                    queue.append(recipe)

        return res