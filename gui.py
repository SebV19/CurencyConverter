import PySimpleGUI as sg


def open_exchange_results():

    f = open("out.txt", 'r')
    result = f.readline()

    layout = [

        [sg.Text("You have exchanged your money:", key="new")], 
        [sg.Text(result, size=(0, 1), key='OUTPUT')],
        [sg.Button("Thank you, Bye!")]

        ]

    window = sg.Window("Second Window", layout, modal=True)
    choice = None
    while True:
        event, values = window.read()
        if event == "Thank you, Bye!":
            break
        
    window.close()
    f.close()



def main():

    f = open("in.txt", 'w')


    sg.theme("DarkGreen5")

    layout = [

        [sg.Text("Choose your Currency: ")],
        [sg.InputText()],
        [sg.Text("Choose the Currency you want to buy:")],
        [sg.InputText()],
        [sg.Text("Amount of money you want to exchange: ")],
        [sg.InputText()],
        [sg.Button("Exchange!"), sg.Button("Cancel")]
    ]

    window = sg.Window("MoneyEchange", layout)

    while True:
        event, values = window.read()
        if event == "Cancel":
            break
        lines = [values[0], values[1], values[2]]
        with open('in.txt', 'w') as f:
            for line in lines:
                f.write(line)
                f.write('\n')

        if event == "Exchange!":
            open_exchange_results()

    window.close()

if __name__ == "__main__":
    main()

    
