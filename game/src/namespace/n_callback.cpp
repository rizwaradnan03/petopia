#include <namespace/n_callback.h>

namespace callback {
    size_t write_curl(void* contents, size_t size, size_t nmemb, std::string* output){
        size_t totalSize = size * nmemb;
        output->append(
            (char*)contents,
            totalSize
        );

        return totalSize;
    }
};