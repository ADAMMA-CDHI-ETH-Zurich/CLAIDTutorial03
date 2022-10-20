#include "CLAID.hpp"

namespace Tutorial
{
    class SubscriberModule : public claid::Module
    {
        DECLARE_MODULE(SubscriberModule)

        private:

            // Variables
            claid::Channel<std::string> stringChannel;

            void initialize()
            {
                // Make sure to use the exact same name of the channel, 
                // that was specified in the PublisherModule.
                stringChannel = subscribe<std::string>("StringChannel", &SubscriberModule::onDataReceived, this);
            }

            void onDataReceived(claid::ChannelData<std::string> data)
            {
                const std::string& str = data->value();
                printf("SubscriberModule received string \"%s\".\n", str.c_str());
            }    
    };
}

REGISTER_MODULE(Tutorial::SubscriberModule)