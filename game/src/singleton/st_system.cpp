#include <singleton/st_system.h>

SINGLETON_system* G_system = nullptr;

SINGLETON_system::SINGLETON_system(){
    try{
        this->connection = new pqxx::connection(
            "host=localhost "
            "port=5432 "
            "dbname=petopia "
            "user=postgres "
            "password=03062005"
        );
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

pqxx::connection& SINGLETON_system::get_connection(){
    return *this->connection;
}
