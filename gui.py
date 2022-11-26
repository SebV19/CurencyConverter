import PySimpleGUI as pg

f = open("in.txt", 'w')

pg.theme("DarkGreen5")

layout = [

    [pg.Text("Choose your Currency: ")],
    [pg.InputText()],
    [pg.Text("Choose the Currency you want to buy:")],
    [pg.InputText()],
    [pg.Text("Amount of money you want to exchange: ")],
    [pg.InputText()],
    [pg.Button("ok"), pg.Button("Cancel")]
]

window = pg.Window("MoneyEchange", layout)

while True:
    event, values = window.read()
    if event == "Cancel":
        break
    lines = [values[0], values[1], values[2]]
    with open('in.txt', 'w') as f:
        for line in lines:
            f.write(line)
            f.write('\n')

window.close()