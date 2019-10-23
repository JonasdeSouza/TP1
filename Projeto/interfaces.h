#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;
 //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServAutenticacao;
class IServUsuario;
class IservCarona;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprAutenticacao {
public:
    virtual void setIServAutenticacao(IServAutenticacao *) = 0;
    virtual ~IAprAutenticacao(){}
    virtual bool Autentica() throw(runtime_error); = 0;
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServAutenticacao {
public:
    virtual ~IServAutenticacao(){}
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprUsuario {
public:
    virtual void setIServUsuario(IServUsuario *) = 0;
    virtual ~IAprUsuario(){}
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServUsuario {
public:
    virtual ~IServUsuario(){}
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IAprCarona {
    public:
    virtual void setIServCarona(IServCarona *) = 0;
    virtual ~IAprCarona(){}
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class IServCarona {
    public:
    virtual ~IServCarona(){}
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // INTERFACES_H_INCLUDED