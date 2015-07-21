//
//  NSObject+Wrapper.m
//  VitamineF
//
//  Created by Hakim on 20/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import "ZetaInit.h"



@implementation ZetaInit

- (int)ZetaInit
{
    return (cometd_init());
}

- (zeta_handshake_manager_t *)ZetaInitHandshake:(const char *)BId DeploymentId:(const char *)DepId Login:(const char *)Login Password:(const char *)Pass
{
    if (BId && DepId && Login && Pass){
        self->hm = zeta_create_mem_handshake_manager(BId, DepId, Login, Pass);
        return (self->hm);
    }
    else
        return NULL;
}

- (zeta_client_t *)ZetaClient:(const char *)Server Transport:(void *)Transport BusinessId:(const char *)BId HandShakeManager:(zeta_handshake_manager_t *)HM resource:(const char *)resource
{
    if (Server && BId && resource && HM)
        self->client = zeta_create_client(Server, cometd_create_long_polling_transport(), BId, HM, resource);
    if (!HM)
        self->client = zeta_create_client(Server, cometd_create_long_polling_transport(), BId, self->hm, resource);
    return (self->client);
}

- (void)ZetaSubscriber:(cometd_client_t *)CometClient CallBacker:(cometd_subscription_callback)CallBack Channel:(char *)Channel
{
    cometd_channel_subscribe(CometClient, CallBack, Channel);
    NSLog(@"CallBack subscribed to : ");
    printf("CallBack Observer set for : %s\n", Channel);
}

- (bool)ZetaHanshake:(zeta_client_t *)Client
{
    if (Client)
        if (!zeta_handshake(Client)){
            self->cli = (cometd_client_impl *)client->cometClient;
            return (true);
        }
        else
        {
            if(!zeta_handshake(self->client)){
                self->cli = (cometd_client_impl *)self->client->cometClient;
                return true;
            }
        }
    return false;
}

- (bool)ZetaMainLoop:(zeta_client_t *)Client
{
    if (self->client->cometClient != NULL)
        return (cometd_main_loop(self->client->cometClient));
    else
        return (cometd_main_loop(Client->cometClient));
}


@end
