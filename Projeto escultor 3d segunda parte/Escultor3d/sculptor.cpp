#include "sculptor.h"
#include <fstream>

int sculptor::getDimX(){
    return nx;
}

int sculptor::getDimY(){
    return ny;
}

int sculptor::getDimZ(){
    return nz;
}

sculptor::sculptor(int _nx, int _ny, int _nz){

    nx = _nx;
    ny = _ny;
    nz = _nz;
    imagemVox = new Voxel **[nx];
    for(int i=0; i<nx;i++){
        imagemVox[i] = new Voxel *[ny];
        for(int j=0; j<ny;j++){
            imagemVox[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                imagemVox[i][j][k].isOn = false;

            }
        }
    }
}

sculptor::~sculptor(){
    for(int i=0;i<nx;i++) {
        for(int j=0;j<ny;j++){
                delete[] imagemVox[i][j];
        }
        delete[] imagemVox[i];
    }
    delete[] imagemVox;
}

void sculptor::putVoxel(int x, int y, int z){

    imagemVox[x][y][z].isOn = true;
    imagemVox[x][y][z].r = r;
    imagemVox[x][y][z].g = g;
    imagemVox[x][y][z].b = b;
    imagemVox[x][y][z].a = a;
}

void sculptor::cutVoxel(int x, int y, int z){
    imagemVox[x][y][z].isOn = false;
}

void sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void sculptor::writeOFF(char *filename)
{
    int v1=0 , v2=1, v3=2, v4=3, v5=4, v6=5, v7=6, v8=7;
    int cont = 0;
    ofstream arq;
    arq.open(filename);
    arq<<"OFF\n";

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(imagemVox[i][j][k].isOn == true){
                    cont = cont +1;
                }
            }
        }
    }

    arq<<cont*8<<" "<<cont*6<<" "<<0<<"\n";
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(imagemVox[i][j][k].isOn == true){
                    arq<<i + (-0.5)<<" "<<j + (0.5)<<" "<<k + (-0.5)<<"\n";
                    arq<<i + (-0.5)<<" "<<j + (-0.5)<<" "<<k + (-0.5)<<"\n";
                    arq<<i + (0.5)<<" "<<j + (-0.5)<<" "<<k + (-0.5)<<"\n";
                    arq<<i + (0.5)<<" "<<j + (0.5)<<" "<<k + (-0.5)<<"\n";
                    arq<<i + (-0.5)<<" "<<j + (0.5)<<" "<<k + (0.5)<<"\n";
                    arq<<i + (-0.5)<<" "<<j + (-0.5)<<" "<<k + (0.5)<<"\n";
                    arq<<i + (0.5)<<" "<<j + (-0.5)<<" "<<k + (0.5)<<"\n";
                    arq<<i + (0.5)<<" "<<j + (0.5)<<" "<<k + (0.5)<<"\n";
                }
            }
        }
    }
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(imagemVox[i][j][k].isOn == true){
                    arq<<4<<" "<<v1<<" "<<v4<<" "<<v3<<" "<<v2<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v5<<" "<<v6<<" "<<v7<<" "<<v8<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v1<<" "<<v2<<" "<<v6<<" "<<v5<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v1<<" "<<v5<<" "<<v8<<" "<<v4<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v4<<" "<<v8<<" "<<v7<<" "<<v3<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v2<<" "<<v3<<" "<<v7<<" "<<v6<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    v1+=8;
                    v2+=8;
                    v3+=8;
                    v4+=8;
                    v5+=8;
                    v6+=8;
                    v7+=8;
                    v8+=8;
                }
            }
        }
    }
}

