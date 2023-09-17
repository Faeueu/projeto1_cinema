#include <iostream>
using namespace std;

const int MAX_FILEIRAS = 10;
const int MAX_LUGARES_POR_FILEIRA = 10;
const float PRECO_POR_LUGAR = 12.50;


void lugar(int cinema[][MAX_LUGARES_POR_FILEIRA]) {
    for (int i = 0; i < MAX_FILEIRAS; i++) {
        for (int j = 0; j < MAX_LUGARES_POR_FILEIRA; j++) {
            cinema[i][j] = 0;
        }
    }
}

void mostrarLugares(int cinema[][MAX_LUGARES_POR_FILEIRA]) {
    cout << "Lugares disponiveis:\n";
    for (int i = 0; i < MAX_FILEIRAS; i++) {
        for (int j = 0; j < MAX_LUGARES_POR_FILEIRA; j++) {
            if (cinema[i][j] == 0) {
                cout << i * MAX_LUGARES_POR_FILEIRA + j + 1 << " "; 
            } else {
                cout << "XX "; 
            }
        }
        cout << endl;
    }
}

bool venderLugar(int cinema[][MAX_LUGARES_POR_FILEIRA], int lugar) {
    if (lugar >= 1 && lugar <= MAX_FILEIRAS * MAX_LUGARES_POR_FILEIRA) {
        int fila = (lugar - 1) / MAX_LUGARES_POR_FILEIRA;
        int coluna = (lugar - 1) % MAX_LUGARES_POR_FILEIRA;

        if (cinema[fila][coluna] == 0) {
            cinema[fila][coluna] = 1;
            cout << "Lugar vendido com sucesso!\n";
            return true; 
        } else {
            cout << "Este lugar ja esta ocupado.\n";
        }
    } else {
        cout << "Lugar invalido.\n";
    }

    return false;
}

int main() {
    int cinema[MAX_FILEIRAS][MAX_LUGARES_POR_FILEIRA];
    lugar(cinema);

    int vendas = 0;
    float lucro = 0.0;
    
    int opc = -1;

    do{
        cout << "1. Mostrar lugares\n";
        cout << "2. Vender lugar\n";
        cout << "3. Encerrar vendas\n";
        cout << "Escolha uma opcao: ";

        cin >> opc;

        if (opc == 1) {
            mostrarLugares(cinema);
            
        }else if(opc == 2){
        	int lugar;
                cout << "Digite o numero do lugar que deseja (1 a 100): ";
                cin >> lugar;

                if (venderLugar(cinema, lugar)) {
                    vendas++;
                    lucro += PRECO_POR_LUGAR;
                }
     
		}else if(opc == 3){
			cout << "Vendas encerradas.\n";
                cout << "Total de lugares vendidos: " << vendas << endl;
                cout << "Lucro total: R$" << lucro << endl;
                return 0;
		
		}else{
			cout << "Opcao invalida.\n";
        }
        
    } while (opc != 0);

    return 0;
}
