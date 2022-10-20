#include "CLAID.hpp"

namespace Tutorial
{
    class PublisherModule : public claid::Module
    {
        DECLARE_MODULE(PublisherModule)

        private:

            // Channel we will use to send data.
            claid::Channel<std::string> stringChannel;

            // Rate at which periodic function will be called
            int periodInMilliseconds; 

            // Number of strings we have sent already.
            int ctr; 

            void initialize()
            {
                ctr = 0;

                // When publishing, we need to specify a name or ID of the channel.
                // This name can be anything and is used to identify the Channel.
                // Subscribers need to provide the exact same name, 
                // if they want to access data from this channel.
                stringChannel = publish<std::string>("StringChannel");

                // PeriodicSenderFunction is just a name we assign to the periodic function.
                // This name can be used to stop the periodic function at a later point.
                // periodInMilliseconds specifies at what rate the function shall be called.
                registerPeriodicFunction("PeriodicSenderFunction",
                     &PublisherModule::periodicSenderFunction, this, periodInMilliseconds);
            }

            void periodicSenderFunction()
            {
                std::string str = "This is the " + std::to_string(ctr) + "th string we send";
                stringChannel.post(str);

                ctr++;
            }    

        public:
            Reflect(PublisherModule,
                reflectMember(periodInMilliseconds);
            )
    };   
}
REGISTER_MODULE(Tutorial::PublisherModule)