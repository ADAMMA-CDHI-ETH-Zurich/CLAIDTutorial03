#include "SubscriberModule.hpp"

namespace HelloWorld
{
    void SubscriberModule::initialize()
    {
        // Make sure to use the exact same name of the channel, 
        // that was specified in the PublisherModule.
        stringChannel = subscribe<std::string>("PersonChannel", &SubscriberModule::onDataReceived, this);
    }

    void SubscriberModule::onDataReceived(claid::ChannelData<std::string> data)
    {
        const std::string& str = data->value();

        printf("SubscriberModule received string \"%s\".\n", str.c_str());
    }    
}

REGISTER_MODULE(HelloWorld::SubscriberModule)