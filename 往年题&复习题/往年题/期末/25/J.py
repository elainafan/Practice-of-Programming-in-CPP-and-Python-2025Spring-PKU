def create_piece(board, pos=[0, 0]):
    sx = pos[0]
    sy = pos[1]

    def move(mo, s):
        nonlocal sx, sy
        global board
        ddx = mo[0]
        ddy = mo[1]
        flag = 1
        for i in range(1, s + 1):
            ax = sx + ddx * i
            ay = sy + ddy * i
            if ax >= 0 and ax <= n - 1 and ay >= 0 and ay <= n - 1 and board[
                    ay][ax] == 'o':
                continue
            else:
                flag = 0
                break
        if flag == 0:
            return "Wrong move"
        else:
            sx = sx + ddx * s
            sy = sy + ddy * s
            return f"[{sx}, {sy}]"

    return move


n, start_x, start_y = map(int, input().split())

# 读取棋盘
board = []
for _ in range(n):
    row = input().strip().split()
    board.append(row)

# 创建棋子
piece = create_piece(board, [start_x, start_y])

# 处理移动指令
try:
    while True:
        cmd = input().strip()
        dx, dy, step = map(int, cmd.split())
        result = piece([dx, dy], step)
        print(result)
except EOFError:
    pass  # 读取到EOF时正常退出
