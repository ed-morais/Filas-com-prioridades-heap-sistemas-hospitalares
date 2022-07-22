from queue import PriorityQueue

q = PriorityQueue()
option = 0
counter1, counter2, counter3, counter4, counter5 = 0, 0, 0, 0, 0

print("\nBem vindo ao programa de gerenciamento de filas hospitalares!\n")

while option != 4:

    option = int(input('''
Escolha uma opção: \n   
[1] Adicionar Paciente   
[2] Chamar próximo da fila   
[3] Mostrar tamanho da fila  
[4] Sair \n\n'''))

    # Adicionar paciente
    if option == 1:
        name = input("\n>>> Nome do paciente: ")
        priority = int(input(">>> Escolha a prioridade:   [1] Vermelho   [2] Laranja   [3] Amarelo   [4] Verde   [5] Azul \n\n"))
        # Usuário escolhe a prioridade do paciente entre 1 e 5
        if priority > 5 or priority < 1:
            print("\n>>> Prioridade inválida!\n")
            break
        # Counter para contar quantos pacientes foram adicionados no mesmo nível de prioridade e assim garantir que se dois itens tiverem a mesma prioridade, o programa remove o item que chegou primeiro
        if priority == 1:
            q.put((priority, counter1, name))
            counter1 += 1
        elif priority == 2:
            q.put((priority, counter2, name))
            counter2 += 1
        elif priority == 3:
            q.put((priority, counter3, name))
            counter3 += 1    
        elif priority == 4:
            q.put((priority, counter4, name))
            counter4 += 1
        elif priority == 5:
            q.put((priority, counter5, name))
            counter5 += 1
        
        print("\n" + name + " foi adicionado à fila de espera.\n")
        
    # Chamar paciente
    elif option == 2:
        if  q.empty():
            print('\nSem Pacientes\n')
            continue
        next = q.get()
        # print(next)
        print("\n" + next[2] + " foi chamado.\n")

    # Mostrar tamanho da fila
    elif option == 3:
        if  q.empty():
            print('\nSem Pacientes\n')
        else:
            print("\nNúmero de pacientes na fila: " + str(q.qsize()) + "\n")
 
    elif option == 4:
        print('\nEncerrando programa...\n')

    else:
        print('\nOpção inválida. Tente novamente.\n')
    print('-' * 100 + '\n')

print('\nPrograma encerrado.\n')
