import PySimpleGUI as pg

pg.theme("DarkAmber")

layout = [
    [pg.Text("Amount of money you want to exchange: ")],
    [pg.InputText()],
    [pg.Text("Choose your Currency: ")],
    [pg.InputText()],
    [pg.Text("Choose the Currency you want to buy:")],
    [pg.InputText()],
    [pg.Button("ok"), pg.Button("Cancel")]
]

window = pg.Window("MoneyEchange", layout)

while True:
    event, values = window.read()
    if event == "Cancel":
        break
    print(values[0], values[1], values[2])

window.close()