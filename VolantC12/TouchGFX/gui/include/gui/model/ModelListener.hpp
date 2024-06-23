#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void change_screen(uint8_t screen) {};
    virtual void update_ui(void* screen) {};
    
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
