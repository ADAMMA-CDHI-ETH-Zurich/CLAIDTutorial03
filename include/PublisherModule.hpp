#pragma once 
#include "CLAID.hpp"

namespace HelloWorld
{
    class PublisherModule : public claid::Module
    {
        DECLARE_MODULE(PublisherModule)

        private:

            // Variables
            claid::Channel<std::string> stringChannel;
            int periodInMilliseconds;
            int ctr;


            // Functions
            void initialize();
            void periodicSenderFunction();

        public:

            Reflect(PublisherModule, 
                reflectMember(periodInMilliseconds);
            )
    };
}