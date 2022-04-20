#ifndef _UCLN_BCNN
#define _UCLN_BCNN

class UCLN_BCNN {
private:
  int a, b;

public:
  UCLN_BCNN(int = 0, int = 0);
  int GetA();
  void SetA(int);
  int GetB();
  void SetB(int);
  void Nhap();
  int TimUSCLN();
  int TimBSCNN();
  void Xuat();
};
#endif
