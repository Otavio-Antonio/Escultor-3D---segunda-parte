#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <fstream>

using namespace std;

struct Voxel{
    float r, g, b, a;
    bool isOn;
};

class sculptor
{
protected:

    int nx, ny, nz;
    float r,g,b,a;
    Voxel ***imagemVox;

public:
    int getDimX();
    int getDimY();
    int getDimZ();

    sculptor(int _nx, int _ny, int _nz);
    ~sculptor();
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void setColor(float r, float g, float b, float alpha);
    void writeOFF(char* filename);
};
#endif // SCULPTOR_H
