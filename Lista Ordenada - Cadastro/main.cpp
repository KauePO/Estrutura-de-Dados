/*
 * Lista linear ordenada.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 11/05/2018
 */
#include <iostream>
#include <fstream>

using namespace std;

#define N 50

// ESTRUTURAL
typedef struct{
    int chave;
    string nome;
    int ra;
    string curso;
} REGISTRO;

typedef struct{
    REGISTRO elementos[N];
    int numeroElementos;
} LISTA;

void inicializarLista(LISTA* l){
    l->numeroElementos = 0;
}
int tamanho(LISTA* l){
    return l->numeroElementos;
}

// EXIBIÇÃO
void exibirLista(LISTA* lista){
    int i;
    cout << "Lista: " << endl;
    cout << "===================================================="<< endl;
    for(i = 0 ; i < lista->numeroElementos; i++) {
        cout << "ID: " << lista->elementos[i].chave << "\n";
        cout << "Nome: " << lista->elementos[i].nome << "\n";
        cout << "RA: " << lista->elementos[i].ra << "\n";
        cout << "Curso: " << lista->elementos[i].curso << "\n\n";
    }	
    cout << "===================================================="<< endl;
        // GRAVAR DADOS
		ofstream arquivo("dados.txt");
        if (arquivo.is_open()) {
    	arquivo << "Lista: " << endl
    << "===================================================="<< endl;
        for(i = 0 ; i < lista->numeroElementos; i++) {
        ofstream arquivo("dados.txt", ios::app);
		if (arquivo.is_open()){
		arquivo << 	"ID: " << lista->elementos[i].chave << "\n"
        << "Nome: " << lista->elementos[i].nome << "\n"
        << "RA: " << lista->elementos[i].ra << "\n"
        << "Curso: " << lista->elementos[i].curso << "\n\n";
    }	
		arquivo.close();	
	}

	} else {
		cerr << "Não foi possível abrir o arquivo para gravação." << endl;
	}

}


// FUNCOES
	//Buscas
int buscaSequencialra(LISTA* lista, REGISTRO registro){
    int i = 0;
    while(i < lista->numeroElementos){
        if(registro.ra == lista->elementos[i].ra) {
        	cout << "ID: " << lista->elementos[i].chave << "\n";
        	cout << "Nome: " << lista->elementos[i].nome << "\n";
        	cout << "RA: " << lista->elementos[i].ra << "\n";
        	cout << "Curso: " << lista->elementos[i].curso << "\n";
		  return i;
        } else {
          i++;
        }
    }
    return -1;
}

int buscaSequencialchave(LISTA* lista, REGISTRO registro){
    int i = 0;
    while(i < lista->numeroElementos){
        if(registro.chave == lista->elementos[i].chave) {
		  return i;
        } else {
          i++;
        }
    }
    return -1;
}


// MUDANÇAS
bool inserirAluno(LISTA* lista, int chave, string curso, string nome, int ra){
    int pos = tamanho(lista);
    if(lista->numeroElementos >= N) { // CASO ESTEJA CHEIA
        return false;
    }
    while( pos > 0 && lista->elementos[pos-1].chave > chave) {
        lista->elementos[pos] = lista->elementos[pos-1];
        pos--;
    }
    lista->elementos[pos].chave = chave;
    lista->elementos[pos].curso = curso;
    lista->elementos[pos].nome = nome;
    lista->elementos[pos].ra = ra;
	lista->numeroElementos++;
    return true;
}
bool removerAluno(LISTA* lista, REGISTRO registro){
    int pos, j;
    pos = buscaSequencialchave(lista, registro);
    if(pos == -1) return false;
    for(j = pos; j< lista->numeroElementos-1; j++){
        lista->elementos[j] = lista->elementos[j+1];
    }
    lista->numeroElementos--;
    return true;
}

// INICIO DO MAIN ///////////////////////////////
int main(void) {
    LISTA lista;
    REGISTRO registro;
    int x;
    bool deu_certo;

    inicializarLista(&lista);
    
    
    inserirAluno(&lista, 1, "DSM", "Alfredo", 1465);
    inserirAluno(&lista, 2, "GE", "Jarro", 5646);
	inserirAluno(&lista, 3, "GE", "Tavares", 4567);
    exibirLista(&lista);
    
    registro.ra = 5646;
    cout << "O aluno esta na posicao: " << buscaSequencialra(&lista, registro)+1 << endl<< endl;
        
	registro.chave = 1;
	removerAluno(&lista, registro);
    exibirLista(&lista);
    
    inserirAluno(&lista, 1, "GE", "AEIOU", 7956);
    exibirLista(&lista);

    

  return 0;
}
