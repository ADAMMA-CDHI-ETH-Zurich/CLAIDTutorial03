#include "PublisherModule.hpp"

namespace HelloWorld
{
    void PublisherModule::initialize()
    {
        ctr = 0;

        // When publishing, we need to specify a name or ID of the channel.
        // This name can be anything and is used to identify the Channel.
        // Subscribers need to provide the exact same name, if they want to access data from this channel.
        stringChannel = publish<std::string>("PersonChannel");

        // PeriodicSenderFunction is just a name we assign to the periodic function.
        // This name can be used to stop the periodic function at a later point.
        // periodInMilliseconds specifies at what rate the function shall be called.
        registerPeriodicFunction("PeriodicSenderFunction", &PublisherModule::periodicSenderFunction, this, periodInMilliseconds);
    }

    void PublisherModule::periodicSenderFunction()
    {
        std::string str = "This is the " + std::to_string(ctr) + "th string we send";
        stringChannel.post(str);

        ctr++;
    }       
}

REGISTER_MODULE(HelloWorld::PublisherModule)