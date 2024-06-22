#ifndef HEADER_PAGE_CONTAINER_HPP
#define HEADER_PAGE_CONTAINER_HPP

#include <gui_generated/containers/header_page_containerBase.hpp>

class header_page_container : public header_page_containerBase
{
public:
    header_page_container();
    virtual ~header_page_container() {}

    virtual void initialize();
protected:
};

#endif // HEADER_PAGE_CONTAINER_HPP
