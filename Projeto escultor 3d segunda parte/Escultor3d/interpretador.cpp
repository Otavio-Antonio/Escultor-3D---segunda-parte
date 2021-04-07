#include "interpretador.h"

Interpretador::Interpretador()
{

}

int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}

vector <FiguraGeometrica*> Interpretador::expor(string filename){

    vector <FiguraGeometrica*> figs;
    ifstream fileIn;
    stringstream ss; // variavel de fluxo
    string s, token; // token é a identificação de cada linha

    fileIn.open(filename); //abre o arquivo indicado pelo filename...

    if(!fileIn.is_open()){ //verifica se o arquivo esta ok...
        cout<<"\"" <<filename <<"\" "<< "- Nao foi encontrado!"<<endl;
        exit(0);
    }

    while(getline(fileIn, s)){  // esse bloco 'while' lê uma linha do arquivo 'fileIn' por vez, e grava na string 's'
        ss.clear(); // limpa o fluxo para não acumular dados
        ss.str(s); // o fluxo 'ss' recebe a string 's'
        ss>>token; // 'ss' grava em 'token' o primeiro literal da string... feito isso, os if's abaixo identificam cada token e sugere um 'rumo' para cada um
        if(token.compare("dim") == 0){
            ss >> dimx >> dimy >> dimz;
        }
        if(token.compare("putvoxel") == 0){
            int x0, y0, z0;
            ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x0,y0,z0,r,g,b,a)); // push.back insere um objeto (putVoxel alocado) na ultima possição do array figs
        }
        if(token.compare("putbox") == 0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a)); // push.back insere um objeto (putBox alocado) na ultima possição do array figs
        }
        if(token.compare("putsphere") == 0){
            int x0, y0, z0, radius;
            ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
            figs.push_back(new putSphere(x0,y0,z0,radius,r,g,b,a)); // push.back insere um objeto (putSphere alocado) na ultima possição do array figs
        }
        if(token.compare("putellipsoid") == 0){
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new putEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a)); // push.back insere um objeto (putEllipsoid alocado) na ultima possição do array figs
        }
        if(token.compare("cutvoxel") == 0){
            int x0, y0, z0;
            ss >> x0 >> y0 >> z0;
            figs.push_back(new cutVoxel(x0,y0,z0)); // push.back insere um objeto (cutVoxel alocado) na ultima possição do array figs
        }
        if(token.compare("cutbox") == 0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1)); // push.back insere um objeto (cutBox alocado) na ultima possição do array figs
        }
        if(token.compare("cutsphere") == 0){
            int x0, y0, z0, radius;
            ss >> x0 >> y0 >> z0 >> radius;
            figs.push_back(new cutSphere(x0,y0,z0,radius)); // push.back insere um objeto (putSphere alocado) na ultima possição do array figs
        }
        if(token.compare("cutellipsoid") == 0){
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz;
            figs.push_back(new cutEllipsoid(x0,y0,z0,rx,ry,rz)); // push.back insere um objeto (putEllipsoid alocado) na ultima possição do array figs
        }
    }

    fileIn.close();

    return figs;
 }
