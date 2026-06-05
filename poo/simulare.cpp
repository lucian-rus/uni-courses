#include <iostream>
#include <vector>

class Dispozitiv {
  private:
    // denumirea produsului
    char *m_denumire;
    // contor de dispozitive -> static, ceea ce inseamna ca putem numara cate instante avem
    static int cntDispozitive;

  public:
    virtual int   getCntDispozitive(void) const           = 0;
    virtual char *getDenumire(void) const                 = 0;
    virtual void  setDenumire(const char *denumire) const = 0;
};

class Senzor: public Dispozitiv {
    
};
