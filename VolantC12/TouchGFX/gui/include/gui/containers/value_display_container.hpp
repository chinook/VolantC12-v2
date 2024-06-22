#ifndef VALUE_DISPLAY_CONTAINER_HPP
#define VALUE_DISPLAY_CONTAINER_HPP

#include <gui_generated/containers/value_display_containerBase.hpp>

class value_display_container : public value_display_containerBase
{
public:
    value_display_container();
    virtual ~value_display_container() {}

    virtual void initialize();
protected:
};

#endif // VALUE_DISPLAY_CONTAINER_HPP
