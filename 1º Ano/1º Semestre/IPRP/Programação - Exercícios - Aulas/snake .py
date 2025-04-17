import time
import random
import functools
import turtle

MAX_X = 600
MAX_Y = 800
DEFAULT_SIZE = 20
SNAKE_SHAPE = 'square'
HIGH_SCORES_FILE_PATH = 'high_scores.txt'
# Controla a velocidade da cobra. Quanto menor o valor, mais rápido é o movimento da cobra.
SPEED = 0.1
snake_body = []


def load_high_score(state):
    highscore = open('high_scores.txt','r')
    state['high_score'] = highscore.read()
    highscore.close()
    
    

    pass

def write_high_score_to_file(state):
    # devem escrever o valor que está em state['high_score'] no ficheiro de high scores
    highscore = open('high_scores.txt','w')
    highscore.write(str(state['high_score'])) 
    update_score_board(state)

    highscore.close

    update_score_board(state)
    pass

def create_score_board(state):
    score_board = turtle.Turtle()
    score_board.speed(0)
    score_board.shape("square")
    score_board.color("black")
    score_board.penup()
    score_board.hideturtle()
    score_board.goto(0, MAX_Y / 2.2)
    state['score_board'] = score_board
    load_high_score(state)
    update_score_board(state)

def update_score_board(state):
    state['score_board'].clear()
    state['score_board'].write("Score: {} High Score: {}".format(state['score'], state['high_score']), align="center", font=("Helvetica", 24, "normal"))

def go_up(state):
    if state['snake']['current_direction'] != 'down':
        state['snake']['current_direction'] = 'up'

def go_down(state):
    if state['snake']['current_direction'] != 'up':
        state['snake']['current_direction'] = 'down'

def go_left(state):
    if state['snake']['current_direction'] != 'right':
        state['snake']['current_direction'] = 'left'

def go_right(state):
    if state['snake']['current_direction'] != 'left':
        state['snake']['current_direction'] = 'right'

def init_state():
    state = {}
    # Informação necessária para a criação do score board
    state['score_board'] = None
    state['new_high_score'] = False
    state['high_score'] = 0
    state['score'] = 0
    # Para gerar a comida deverá criar um nova tartaruga e colocar a mesma numa posição aleatória do campo
    state['food'] = None
    state['window'] = None
    snake = {
        'head': None,                  # Variável que corresponde à cabeça da cobra
        'current_direction': None
    }
    state['snake'] = snake
    return state

def setup(state):
    window = turtle.Screen()
    window.setup(width=MAX_X, height=MAX_Y)
    window.listen()
    window.onkey(functools.partial(go_up, state), 'w')
    window.onkey(functools.partial(go_down, state), 's')
    window.onkey(functools.partial(go_left, state), 'a')
    window.onkey(functools.partial(go_right, state), 'd')
    window.tracer(0)
    state['window'] = window
    snake = state['snake']
    snake['current_direction'] = 'stop'
    snake['head'] = turtle.Turtle()
    snake['head'].shape(SNAKE_SHAPE)
    snake['head'].showturtle()
    snake['head'].pu()
    snake['head'].color('green')
    create_score_board(state)
    create_food(state)

def move(state):
    snake = state['snake']
    for index in range(len(snake_body)-1,0,-1):
        x = snake_body[index-1].xcor()
        y = snake_body[index-1].ycor()
        snake_body[index].goto(x,y)

    if len(snake_body)>0:
        x = snake["head"].xcor()
        y = snake["head"].ycor()
        snake_body[0].goto(x,y)
        
    if state['snake']['current_direction'] == 'up':
        snake["head"].setheading(90)
        snake["head"].fd(+20)
    elif state['snake']['current_direction'] == 'down':
        snake["head"].setheading(270)
        snake["head"].fd(+20)
    elif state['snake']['current_direction'] == 'right':
        snake["head"].setheading(0)
        snake["head"].fd(+20)
    elif state['snake']['current_direction'] == 'left':
        snake["head"].setheading(180)
        snake["head"].fd(+20)    
    snake = state['snake']

def create_food(state):
    ''' 
        Função responsável pela criação da comida. Note que elas deverão ser colocadas em posições aleatórias, mas dentro dos limites do ambiente.
    '''
    food = state['food']
    snake = state['snake']
    state['food'] = turtle.Turtle()
    food_posX = random.randint(-280, 280)
    food_posY = random.randint(-380, 380)
    state['food'].shape("circle")
    state['food'].color("red")
    state['food'].pu()
    state['food'].goto(food_posX,food_posY)
    state['food'].pd()
    food = state['food']
    snake = state['snake']

    # a informação sobre a comida deve ser guardada em state['food']

def check_if_food_to_eat(state):
    food = state["food"]
    snake = state["snake"]
    head = snake["head"]
    score = state['score']
    if snake["head"].distance(state["food"]) < 15:
        state['score'] += 10
        update_score_board(state)
        food_posX = random.randint(-280, 280)
        food_posY = random.randint(-380, 380)
        food.pu()
        food.goto(food_posX,food_posY)
        food.pd()

        
        new_body = turtle.Turtle()
        new_body.speed(0)
        new_body.shape("square")
        new_body.color("black")
        new_body.penup()
        snake_body.append(new_body)

        if int(state['score']) > int(state['high_score']):
            state['new_high_score'] = True
            state['high_score'] = state['score']
            update_score_board(state)

        
    # para ler ou escrever os valores de high score, score e new high score, devem usar os respetivos campos do state: state['high_score'], state['score'] e state['new_high_score']

def boundaries_collision(state):
    snake = state['snake']
    head = snake["head"]
    if head.xcor() < -300 or head.xcor() > 300 or head.ycor() < -400 or head.ycor() > 400:
        return True
    else:
        return False
    


def check_collisions(state):
    snake = state["snake"]
    
    for new_body in snake_body:
        if new_body.distance(snake["head"]) == 0 :
            return True

    snake = state['snake']
    return boundaries_collision(state)

def main():
    state = init_state()
    setup(state)
    while not check_collisions(state):
        state['window'].update()
        check_if_food_to_eat(state)
        move(state)
        time.sleep(SPEED) 
    print("YOU LOSE!")
    if state['new_high_score']:
        write_high_score_to_file(state)


main()
