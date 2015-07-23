//
//  main.m
//  CommandLine
//
//  Created by Hakim on 22/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "libZeta.h"
#import "jansson.h"
#import "ZetaInit.h"

bool    Toto()
{
    printf("CallBack is working !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    exit (0);
    return true;
}

bool Titi()
{
    printf("CallBack Is fucking Working !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");
    return true;
}

typedef bool (*cometd_subscription_callback)(cometd_client_t * client, cometd_message * message);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"Logging");
        ZetaInit *Test = [[ZetaInit alloc] init];
    
         [Test ZetaInit];
         [Test ZetaInitHandshake:"GmY-HuzW" DeploymentId:"KZyH" Login:"test2" Password:"password"];
         [Test ZetaClient:"http://m.zpush.ovh:8080/str/strd" Transport:NULL resource:"resource0"];
         [Test ZetaSubscriber:Toto Channel:"/service/GmY-HuzW/2vC3/ls"];
         [Test ZetaSubscriber:Titi Channel:"/service/GmY-HuzW/2v_u/execute"];
         if (![Test ZetaHanshake]){
         while (![Test ZetaMainLoop]){
             [Test ListFolder:"/" SDepId:"2vC3"];
             //[Test ExecuteAction:"2v_u" Cmd:easy ExtraData:ftw Adresser:"ShDmD1_ZFwNnmmjLxJCroA" AdresserResource:"resource0" Owner:"ShDmD1_ZFwNnmmjLxJCroA" Resource:"resource1"];
            }
         }else
         printf("Things aren't working as expected\n");
    }
    
    return 0;
}