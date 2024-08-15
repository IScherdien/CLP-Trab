import ctypes #Biblioteca para chamar funções em C
import matplotlib.pyplot as plt #Biblioteca para plotar gráficos

def plot(vet, vet_size, lib):
    plt.ion()  # Habilita o modo interativo do matplotlib

    for step in range(1, vet_size):
        plt.clf()  # Limpa o gráfico

        # Chama a função C para realizar um passo na ordenação
        lib.insertion_step(vet, vet_size, step)

        vet_list = [vet[i] for i in range(vet_size)]

        # Re plota o grafico no estado atual
        plt.bar(range(vet_size), vet_list)
        plt.draw()
        plt.pause(0.01)  # Pause to allow the plot to update

    plt.ioff()  # Turn off interactive mode
    plt.show()

def main():
    #Carrega a biblioteca compartilhada do C    
    lib = ctypes.CDLL('build/biblioteca.so')

    vet_size = 100
    vet = (ctypes.c_int * vet_size)()

    # Define os tipos de argumentos da função C
    lib.insertion_step.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)

    # Chama a função C para popular e embaralhar o vetor
    lib.PopularSqc(vet, vet_size)
    lib.embaralhar(vet, vet_size)

    # Chama a função para plotar o gráfico
    plot(vet, vet_size, lib)

if __name__ == '__main__':
    main()