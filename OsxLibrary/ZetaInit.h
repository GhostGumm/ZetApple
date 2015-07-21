//
//  NSObject+Wrapper.h
//  VitamineF
//
//  Created by Hakim on 20/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "libZeta.h"
#import "jansson.h"


@interface ZetaInit: NSObject{
    
@public zeta_handshake_manager_t            *hm;
@public zeta_client_t                       *client;
@public cometd_client_impl                  *cli;
    
}

- (int)ZetaInit;

- (zeta_handshake_manager_t *)ZetaInitHandshake:(const char *)BId DeploymentId:(const char *)DepId Login:(const char *)Login Password:(const char *)Pass;

- (zeta_client_t *)ZetaClient:(const char *)Server Transport:(void *)Transport BusinessId:(const char *)BId HandShakeManager:(zeta_handshake_manager_t *)hm resource:(const char *)resource;

- (void)ZetaSubscriber:(cometd_client_t *)CometClient CallBacker:(cometd_subscription_callback)CallBack Channel:(char *)Channel;

- (bool)ZetaHanshake:(zeta_client_t *)Client;

- (bool)ZetaMainLoop:(zeta_client_t *)client;

@end