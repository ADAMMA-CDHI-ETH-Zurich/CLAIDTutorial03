#pragma once 
#include "CLAID.hpp"

namespace HelloWorld
{
    class SubscriberModule : public claid::Module
    {
        DECLARE_MODULE(SubscriberModule)

        private:

            // Variables
            claid::Channel<std::string> stringChannel;

            // Functions
            void initialize();
            void onDataReceived(claid::ChannelData<std::string> data);

        public:

            // No reflect function necessary, this Module does not have any properties.
           
    };
}