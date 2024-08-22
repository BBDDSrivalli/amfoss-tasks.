# Documentation for Snake Game

## Overview

The Snake Game is a classic arcade game implemented using Python and the Tkinter library. The objective of the game is to control a snake that moves around the screen, eating food and growing in size. The game ends when the snake collides with the screen's boundaries or its own body. This project demonstrates basic game development concepts and the use of Tkinter for graphical interfaces in Python.

## Functionality

### Classes

#### Snake

- **`__init__`**
  - Initializes the snake with a default body size and creates the initial snake segments.

- **`move`**
  - Moves the snake in the current direction and handles the growth of the snake when it eats food.

- **`change_direction`**
  - Updates the direction of the snake based on user input.

- **`check_collision`**
  - Checks for collisions with the game boundaries or the snake's own body.

#### Food

- **`__init__`**
  - Initializes the food at a random location within the game boundaries.

### Functions

#### `next_turn(snake, food)`

- Handles the movement of the snake, checks for collisions, and manages the interaction with food. It also schedules the next move of the snake.

#### `change_direction(new_direction)`

- Updates the snake's direction based on user input, ensuring the snake cannot move in the opposite direction.

#### `check_collisions(snake)`

- Checks if the snake has collided with the game boundaries or itself, indicating a game over condition.

#### `game_over()`

- Displays a "GAME OVER" message on the canvas when the game ends.

## Implementation Details

### Game Initialization

The game window is set up using Tkinter, with a canvas for rendering the game elements and a label for displaying the score. The snake and food are initialized, and the game loop is started using `next_turn`.

### Movement and Controls

The snake's movement is controlled by arrow key events bound to the `change_direction` function. The snake's position is updated based on the current direction, and collision checks are performed after each move.

### Food Interaction

When the snake's head collides with the food, the score is updated, and a new food item is placed on the canvas. The snake grows in size by adding a new segment.

### Collision Handling

The game checks for collisions with the boundaries or the snake's body. If a collision is detected, the `game_over` function is called to display the game over message.

## Code Example

Here’s a snippet showing how the `next_turn` function handles the snake's movement and interaction with food:

```python
def next_turn(snake, food):

    x, y = snake.coordinates[0]

    if direction == "up":
        y -= SPACE_SIZE
    elif direction == "down":
        y += SPACE_SIZE
    elif direction == "left":
        x -= SPACE_SIZE
    elif direction == "right":
        x += SPACE_SIZE

    snake.coordinates.insert(0, (x, y))

    square = canvas.create_rectangle(x, y, x + SPACE_SIZE, y + SPACE_SIZE, fill=SNAKE_COLOR)

    snake.squares.insert(0, square)

    if x == food.coordinates[0] and y == food.coordinates[1]:

        global score

        score += 1

        label.config(text="Score:{}".format(score))

        canvas.delete("food")

        food = Food()

    else:

        del snake.coordinates[-1]

        canvas.delete(snake.squares[-1])

        del snake.squares[-1]

    if check_collisions(snake):
        game_over()

    else:
        window.after(SPEED, next_turn, snake, food)

