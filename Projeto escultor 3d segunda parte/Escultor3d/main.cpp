#include <iostream>
#include "figurageometrica.h"
#include "interpretador.h"
#include <vector>

using namespace std;

int main()
{
    sculptor *s1; // criei um ponteiro para sculptor

    vector<FiguraGeometrica*> figs; // criei um 'array' de figuras geometricas

    Interpretador dados; // o interpretador deve abrir os dados que serão recebidos de um txt

    figs = dados.expor("aaa.txt");

 /*
    figs receberá os dados de interpretador, ou seja, figs será um array de figuras de acordo com o txt.
    Por exemplo, se no txt estiver um putvoxel e um putsphere, figs vai ser um array de 2 figuras alocadas, um voxel
    e uma esfera.
 */

    s1 = new sculptor(dados.getDimx(),dados.getDimy(),dados.getDimz());
    // aloca um sculptor, passando as dimensões para dentro do sculptor que fara a alocação de uma matriz 3D pelo seu construtor


    for(size_t i=0; i<figs.size(); i++){ // 'size_t' é um tipo fundamental capaz de representar qualquer tamanho de objeto
        cout<<"Draw"<<endl;
        figs[i]->draw(*s1);
    }
 /*
    Esse bloco 'for': entra em uma posição do array figs (onde tem uma alocação de um objeto que queremos desenhar),
    executa o método Draw da FiguraGeometrica que apontará para o método draw do objeto,
    em seguida grava esse desenho no sculptor alocado anteriormente.
*/

    s1->writeOFF((char*)"teste.off"); // chama o método writeOFF do escultor para gravar a imagem de saida.

    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }
    // esse bloco 'for': libera cada posição da figs ou seja libera cada figura que eu aloquei dentro do interpretrador.

    delete s1; // por fim, libera o sculptor alocado

    cout << "fim!";
    return 0;
}
