import ctypes
import matplotlib.pyplot as plt

def main():
    # Load the shared library into c types.
    lib = ctypes.CDLL('build/biblioteca.so')

    vet_size = 100
    vet = (ctypes.c_int * vet_size)()
    
    index = (ctypes.c_int * vet_size)()
    lib.PopularSqc(index, vet_size)    
    index = list(index)
        
    # Chama a função C para popular o vetor
    lib.PopularSqc(vet, vet_size)
    lib.embaralhar(vet, vet_size)
    
    vet_list = list(vet)
    
    plt.plot(vet_list, 'ro')    
    	    
if __name__ == '__main__':
    main()