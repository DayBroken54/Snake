from build.out import libgame as lg
import tkinter as tk

game = lg.Game()
direction = lg.Direction.RIGHT

root = tk.Tk()
root.title("Snake")
root.geometry("1920x1080")

def restart():
    global direction
    game.reset()
    direction = lg.Direction.RIGHT
    main()

btn = tk.Button(root, text="Restart", command=restart)
btn.pack()
TILE_SIZE = 40
canvas = tk.Canvas(
    root,
    width = (game.get_WIDTH() + 1) * TILE_SIZE,
    height = (game.get_HEIGHT() + 1) * TILE_SIZE
)
canvas.pack()

def on_key(event) -> None:
    global direction

    if event.keysym in ("w", "Up"):
        direction = lg.Direction.UP
    if event.keysym in ("a", "Left"):
        direction = lg.Direction.LEFT
    if event.keysym in ("s", "Down"):
        direction = lg.Direction.DOWN    
    if event.keysym in ("d", "Right"):
        direction = lg.Direction.RIGHT

root.bind("<Key>", on_key)
root.focus_force()

def draw() -> None:
    canvas.delete("all")

    for tile in game.get_board_state():
        x1 = tile.get_x() * TILE_SIZE
        y1 = tile.get_y() * TILE_SIZE
        x2 = x1 + TILE_SIZE
        y2 = y1 + TILE_SIZE

        tile_type = tile.get_type()
        if tile_type == lg.Cell.WALL:
            color = "black"
        elif tile_type == lg.Cell.FOOD:
            color = "red" 
        elif tile_type == lg.Cell.HEAD:
            color = "green"
        elif tile_type == lg.Cell.BODY:
            color = "darkgreen"
        else: color = "white"

        canvas.create_rectangle(x1, y1, x2, y2, fill=color)

def tick():
    game.move(direction)
    game.check_win()
    draw()

    if game.get_runtime_state() == lg.Runtime.RUNNING:
        root.after(200, tick)

def main() -> None:
    draw()
    root.after(200, tick)
    root.mainloop()

main()