#ifndef SINGLETON_DATABASE_H
#define SINGLETON_DATABASE_H

#include <config/c_pch.h>

class SINGLETON_system {
    public:
        SINGLETON_system();

        pqxx::connection& get_connection();

    private:
        pqxx::connection* connection;
};

extern SINGLETON_system* G_system;

#endif