#include <iostream>
#include <fstream>

using namespace std;

void ZerarVetor(int* vetor, int tam);
void Movimentacao(int comandos, int* vetor, int larg, ifstream &arqE);
void GerarImagem(int* vetor, int tam, int larg);

int main(){

    ifstream arquivoE;
    arquivoE.open("PK.txt");

    if (arquivoE.is_open()){
   
        int largura = 0, altura = 0;
            arquivoE >> largura >> altura;
        
        int TamanhoVetor = altura * largura;
        
        int* superficie = new int [TamanhoVetor];
        ZerarVetor(superficie, TamanhoVetor);
    
        int qtdComandos = 0;
            arquivoE >> qtdComandos;
    
        Movimentacao(qtdComandos, superficie, largura, arquivoE);
        arquivoE.close();
        
        GerarImagem(superficie, TamanhoVetor, largura);
        
        delete superficie;
    
    }

    else cout << "O arquivo nao foi aberto corretamente!" << endl;   
    

return 0; 
}

void Movimentacao(int comandos, int* vetor, int larg, ifstream &arqE){
    bool bracoAbaixado = false;
    int PosicaoBraco = 0;
    int distancia = 0;
    char opcao;
    int linha = 0;
    int coluna = 0;
    
    while(comandos>0){
        arqE >> opcao;
        
        switch(opcao){
            case 's':
                bracoAbaixado = false;
                break;
            
            case 'a':
                bracoAbaixado = true;
                PosicaoBraco = (linha*larg) + coluna;
                vetor[PosicaoBraco] = bracoAbaixado;
                break;
            
            case 'e':
                arqE >> distancia;

                while(distancia>0){
                    coluna--;
                    distancia--;

                    PosicaoBraco = (linha*larg) + coluna;
                    
                    if(bracoAbaixado==true){
                        vetor[PosicaoBraco] = bracoAbaixado;
                    }                    
                }
                break;
                
            case 'd':
                arqE >> distancia;

                while(distancia>0){
                    coluna++;
                    distancia--;

                    PosicaoBraco = (linha*larg) + coluna;
                    
                    if(bracoAbaixado==true){
                        vetor[PosicaoBraco] = bracoAbaixado;
                    }                    
                }
                break;
            
            case 'c':
                //cout << "qtd movimento: ";
                arqE >> distancia;

                while(distancia>0){
                    linha--;
                    distancia--;

                    PosicaoBraco = (linha*larg) + coluna;
                    
                    if(bracoAbaixado==true){
                        vetor[PosicaoBraco] = bracoAbaixado;
                    }                    
                }
                break;
            
            case 'b':
                arqE >> distancia;

                while(distancia>0){
                    linha++;
                    distancia--;

                    PosicaoBraco = (linha*larg) + coluna;
                    
                    if(bracoAbaixado==true){
                        vetor[PosicaoBraco] = bracoAbaixado;
                    }                    
                }
                break;     
        }
        
        comandos--;
    }
}

void GerarImagem(int* vetor, int tam, int larg){
    ofstream arquivoS;
    arquivoS.open("PK.pbm");

    arquivoS << "P1\n";
    arquivoS << "# Patrick Oliveira de Brito\n";
    arquivoS << larg << " " << tam/larg << endl;

    for(int i=0; i<tam; i++){
        for(int j=0; j<larg; j++){
            arquivoS << vetor[i] << " ";
            i++;
        }
        i--;
        arquivoS << "\n";
    }
    arquivoS.close();
}

void ZerarVetor(int* vetor, int tam){
    for(int i=0; i < tam; i++){
        vetor[i] = 0;
    }
}


