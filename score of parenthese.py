class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        if (m + n - 1) % 2 != 0 or grid[0][0] == ')' or grid[m-1][n-1] == '(':
            return False
            
        max_balance = (m + n) // 2
        
        visited = set()
        
        def dfs(r, c, balance):
            if balance < 0 or balance > max_balance:
                return False
                
            if r == m - 1 and c == n - 1:
                return balance == 0
                
            state = (r, c, balance)
            if state in visited:
                return False
            visited.add(state)
            
            if r + 1 < m:
                next_bal = balance + (1 if grid[r+1][c] == '(' else -1)
                if dfs(r + 1, c, next_bal):
                    return True
                    
            if c + 1 < n:
                next_bal = balance + (1 if grid[r][c+1] == '(' else -1)
                if dfs(r, c + 1, next_bal):
                    return True
                    
            return False

        return dfs(0, 0, 1)
