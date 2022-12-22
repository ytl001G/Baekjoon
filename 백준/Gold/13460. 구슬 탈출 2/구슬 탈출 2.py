class Board:
    def __init__(self, board, n, m, depth=0):
        self.n = n
        self.m = m
        self.board = board.copy()
        self.R = board.index('R')
        self.B = board.index('B')
        self.Ralive = True
        self.Balive = True
        self.depth = depth
    
    def __repr__(self):
        s = ''
        for i in range(self.n):
            for j in range(self.m):
                s += self.board[i*self.m +j]
            s += '\n'

        return s
    
    def switcher(self, id1, id2):
        self.board[id1], self.board[id2] = self.board[id2], self.board[id1]
    
    @classmethod
    def tiltUp(cls, board):
        newboard = Board(board.board, board.n, board.m, board.depth+1)
        
        while True:
            swiched = False
            
            if newboard.R - newboard.m >= 0 and newboard.Ralive:
                if newboard.board[newboard.R - newboard.m] == '.':
                    newboard.switcher(newboard.R, newboard.R - newboard.m)

                    swiched = True
                    newboard.R -= newboard.m
                
                if newboard.board[newboard.R - newboard.m] == 'O':
                    newboard.board[newboard.R] = '.'
                    newboard.Ralive = False

                    swiched = True
                
            if newboard.B - newboard.m >= 0 and newboard.Balive:
                if newboard.board[newboard.B - newboard.m] == '.':
                    newboard.switcher(newboard.B, newboard.B - newboard.m)
                    
                    swiched = True
                    newboard.B -= newboard.m
                    
                if newboard.board[newboard.B - newboard.m] == 'O':
                    newboard.board[newboard.B] = '.'
                    newboard.Balive = False
                    
                    swiched = True

            if not swiched:
                break
        
        return newboard
    
    @classmethod
    def tiltDown(cls, board):
        newboard = Board(board.board, board.n, board.m, board.depth+1)
        
        while True:
            swiched = False
            
            if newboard.R + newboard.m < newboard.n * newboard.m and newboard.Ralive:
                if newboard.board[newboard.R + newboard.m] == '.':
                    newboard.switcher(newboard.R, newboard.R + newboard.m)
                    
                    swiched = True
                    newboard.R += newboard.m

                if newboard.board[newboard.R + newboard.m] == 'O':
                    newboard.board[newboard.R] = '.'
                    newboard.Ralive = False

                    swiched = True
                
            if newboard.B + newboard.m < newboard.n * newboard.m and newboard.Balive:
                if newboard.board[newboard.B + newboard.m] == '.':
                    newboard.switcher(newboard.B, newboard.B + newboard.m)
                    
                    swiched = True
                    newboard.B += newboard.m
                    
                if newboard.board[newboard.B + newboard.m] == 'O':
                    newboard.board[newboard.B] = '.'
                    newboard.Balive = False
                    
                    swiched = True

            if not swiched:
                break
        
        return newboard
        
    @classmethod
    def tiltLeft(cls, board):
        newboard = Board(board.board, board.n, board.m, board.depth+1)
        
        while True:
            swiched = False
            
            if newboard.R % newboard.m - 1 >= 0 and newboard.Ralive:
                if newboard.board[newboard.R - 1] == '.':
                    newboard.switcher(newboard.R, newboard.R - 1)

                    swiched = True
                    newboard.R -= 1
                
                if newboard.board[newboard.R - 1] == 'O':
                    newboard.board[newboard.R] = '.'
                    newboard.Ralive = False

                    swiched = True
                
            if newboard.B % newboard.m - 1 >= 0 and newboard.Balive:
                if newboard.board[newboard.B - 1] == '.':
                    newboard.switcher(newboard.B, newboard.B - 1)
                        
                    swiched = True
                    newboard.B -= 1
                    
                if newboard.board[newboard.B - 1] == 'O':
                    newboard.board[newboard.B] = '.'
                    newboard.Balive = False
                        
                    swiched = True

            if not swiched:
                break
        
        return newboard
        
    @classmethod
    def tiltRight(cls, board):
        newboard = Board(board.board, board.n, board.m, board.depth+1)
        
        while True:
            swiched = False
            
            if newboard.R % newboard.m + 1 < newboard.m and newboard.Ralive:
                if newboard.board[newboard.R + 1] == '.':
                    newboard.switcher(newboard.R, newboard.R + 1)

                    swiched = True
                    newboard.R += 1

                if newboard.board[newboard.R + 1] == 'O':
                    newboard.board[newboard.R] = '.'
                    newboard.Ralive = False

                    swiched = True
                
            if newboard.B % newboard.m + 1 < newboard.m and newboard.Balive:
                if newboard.board[newboard.B + 1] == '.':
                    newboard.switcher(newboard.B, newboard.B + 1)
                        
                    swiched = True
                    newboard.B += 1
                    
                if newboard.board[newboard.B + 1] == 'O':
                    newboard.board[newboard.B] = '.'
                    newboard.Balive = False
                        
                    swiched = True

            if not swiched:
                break
        
        return newboard
        

def boardcode(board):
    return ''.join(board.board)

def main():
    n, m = map(int, input().split())
    board = []
    
    
    for _ in range(n):
        board.extend(list(input()))
    
    B = Board(board, n, m)
        
    queue = [B]
    marked = []
    
    
    ans = []
    while queue:
        now = queue.pop(0)

        for child in (Board.tiltUp(now), Board.tiltDown(now), Board.tiltLeft(now), Board.tiltRight(now)):
            if boardcode(child) not in marked and child.depth <= 10:                
                if 'R' not in child.board and 'B' in child.board:
                    ans.append(child.depth)
                    continue
                    
                if 'B' not in child.board:
                    continue

                queue.append(child)
                marked.append(boardcode(child))

    if ans:
        print(min(ans))
    else:
        print(-1)

main()
    