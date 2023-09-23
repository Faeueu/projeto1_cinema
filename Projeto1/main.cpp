#include <iostream>
using namespace std;

const int TOTAL_FILEIRAS = 10;
const int TOTAL_LUGARES = 10;
const float PRECO = 12.50;


void lugar(int cinema[][TOTAL_LUGARES]) {
    for (int i = 0; i < TOTAL_FILEIRAS; i++) {
        for (int j = 0; j < TOTAL_LUGARES; j++) {
            cinema[i][j] = 0;
        }
    }
}

void mostrarLugares(int cinema[][TOTAL_LUGARES]) {
    cout << "Lugares disponiveis:\n";
    for (int i = 0; i < TOTAL_FILEIRAS; i++) {
        for (int j = 0; j < TOTAL_LUGARES; j++) {
            if (cinema[i][j] == 0) {
                cout << i * TOTAL_LUGARES + j + 1 << " "; 
            } else {
                cout << "XX "; 
            }
        }
        cout << endl;
    }
}

bool comprarLugar(int cinema[][TOTAL_LUGARES], int lugar) {
    if (lugar >= 1 && lugar <= TOTAL_FILEIRAS * TOTAL_LUGARES) {
        int fila = (lugar - 1) / TOTAL_LUGARES;
        int coluna = (lugar - 1) % TOTAL_LUGARES;

        if (cinema[fila][coluna] == 0) {
            cinema[fila][coluna] = 1;
            cout << "Lugar comprado com sucesso!\n";
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
    int cinema[TOTAL_FILEIRAS][TOTAL_LUGARES];
    lugar(cinema);

    int vendas = 0;
    float valor = 0.0;
    
    int opc = -1;

    do{
        cout << "1. Mostrar lugares\n";
        cout << "2. Comprar lugar\n";
        cout << "3. Encerrar compras\n";
        cout << "Escolha uma opcao: ";

        cin >> opc;

        if (opc == 1) {
            mostrarLugares(cinema);
            
        }else if(opc == 2){
        	int lugar;
                cout << "Digite o numero do lugar que deseja (1 a 100): ";
                cin >> lugar;

                if (comprarLugar(cinema, lugar)) {
                    vendas++;
                    valor += PRECO;
                }

		}else if(opc == 3){
			cout << "Vendas encerradas.\n";
                cout << "Total de lugares comprados: " << vendas << endl;
                cout << "Valor total: R$" << valor << endl;
                return 0;
		
		}else{
			cout << "Opcao invalida.\n";
        }
        
    } while (opc != 0);

    return 0;
}
